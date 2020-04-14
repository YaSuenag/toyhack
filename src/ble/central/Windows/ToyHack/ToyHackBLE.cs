using System;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.Devices.Bluetooth;
using Windows.Devices.Bluetooth.GenericAttributeProfile;
using Windows.Storage.Streams;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Collections.Generic;

namespace ToyHack
{
    public class ToyHackBLE : IDisposable
    {
        public static Guid AdvertiseUUID => new Guid("36b50eb130c741a487a8b250e30fb15d");
        public static Guid ToyHackServiceUUID => new Guid("36b50eb130c741a487a8b250e30fc000");

        public static Guid ModuleNameUUID => new Guid("36b50eb130c741a487a8b250e30fc001");
        public static Guid LibraryNameUUID => new Guid("36b50eb130c741a487a8b250e30fc002");

        public static Guid YokaiWatchServiceUUID => new Guid("f1205471f8cd466ca9a8a4e377044000");
        public static Guid SetMedalUUID => new Guid("f1205471f8cd466ca9a8a4e377044001");
        public static Guid EjectMedalUUID => new Guid("f1205471f8cd466ca9a8a4e377044002");

        private BluetoothLEDevice device;

        private GattDeviceService PrimaryService;

        private GattDeviceService ToyHackService;

        private IReadOnlyList<GattCharacteristic> PrimaryCharacteristics;

        private IReadOnlyList<GattCharacteristic> ToyHackCharacteristics;

        private string _moduleName;
        private string _libraryName;

        public string ModuleName => _moduleName;
        public string LibraryName => _libraryName;

        public ToyHackBLE(ulong address)
        {
            init(address).Wait();
        }

        private async Task<string> PrimaryCharacteristicValueToString(Guid characteristicGuid)
        {
            var characteristic = PrimaryCharacteristics.Where(c => c.Uuid == characteristicGuid)
                                                       .First();
            var buf = (await characteristic.ReadValueAsync()).Value;

            byte[] bytes = new byte[buf.Length];
            using (var reader = DataReader.FromBuffer(buf))
            {
                reader.ReadBytes(bytes);
            }

            return Encoding.UTF8.GetString(bytes, 0, bytes.Length);
        }

        private async Task init(ulong address)
        {
            device = await BluetoothLEDevice.FromBluetoothAddressAsync(address);
            PrimaryService = (await device.GetGattServicesForUuidAsync(ToyHackServiceUUID)).Services.First();
            PrimaryCharacteristics = (await PrimaryService.GetCharacteristicsAsync()).Characteristics;

            _moduleName = await PrimaryCharacteristicValueToString(ModuleNameUUID);
            _libraryName = await PrimaryCharacteristicValueToString(LibraryNameUUID);

            switch (_moduleName)
            {
                case "Gaburevolver":
                    // TODO
                    break;
                case "Minityra":
                    // TODO
                    break;
                case "Yokai Watch":
                    ToyHackService = (await device.GetGattServicesForUuidAsync(YokaiWatchServiceUUID)).Services.First();
                    ToyHackCharacteristics = (await ToyHackService.GetCharacteristicsAsync()).Characteristics;
                    break;
            }
        }

        public async void WriteUByte(byte value, Guid characteristicGuid)
        {
            var characteristic = ToyHackCharacteristics.Where(c => c.Uuid == characteristicGuid)
                                                       .First();
            var array = BitConverter.GetBytes(value);
            await characteristic.WriteValueAsync(array.AsBuffer(), GattWriteOption.WriteWithoutResponse);
        }

        public async void WriteUShortAsBE(ushort value, Guid characteristicGuid)
        {
            var array = BitConverter.GetBytes(value);
            if (BitConverter.IsLittleEndian)
            {
                // The value should be transmit in big endian
                Array.Reverse(array);
            }

            var characteristic = ToyHackCharacteristics.Where(c => c.Uuid == characteristicGuid)
                                                       .First();
            await characteristic.WriteValueAsync(array.AsBuffer(), GattWriteOption.WriteWithoutResponse);
        }

        public void Dispose()
        {
            device.Dispose();
        }
    }
}
