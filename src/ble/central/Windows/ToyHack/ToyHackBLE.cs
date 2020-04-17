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
    public struct YokaiWatchUUIDs
    {
        public static Guid Service => new Guid("f1205471f8cd466ca9a8a4e377044000");
        public static Guid SetMedal => new Guid("f1205471f8cd466ca9a8a4e377044001");
        public static Guid EjectMedal => new Guid("f1205471f8cd466ca9a8a4e377044002");
    }

    public struct GaburevolverUUIDs
    {
        public static Guid Service => new Guid("0bd173ff1029456d9df38c58a2962000");
        public static Guid OpenSetter => new Guid("0bd173ff1029456d9df38c58a2962001");
        public static Guid SetJudenchi => new Guid("0bd173ff1029456d9df38c58a2962002");
        public static Guid CloseSetter => new Guid("0bd173ff1029456d9df38c58a2962003");
        public static Guid Rotate => new Guid("0bd173ff1029456d9df38c58a2962004");
        public static Guid Trigger => new Guid("0bd173ff1029456d9df38c58a2962005");
        public static Guid DockMinityra => new Guid("0bd173ff1029456d9df38c58a2962006");
        public static Guid UndockMinityra => new Guid("0bd173ff1029456d9df38c58a2962007");
        public static Guid DockGaburicalibur => new Guid("0bd173ff1029456d9df38c58a2962008");
        public static Guid UndockGaburicalibur => new Guid("0bd173ff1029456d9df38c58a2962009");
    }

    public struct MinityraUUIDs
    {
        public static Guid Service => new Guid("b73244fb2df84cd583300f6b70d68000");
        public static Guid SetJudenchi => new Guid("b73244fb2df84cd583300f6b70d68001");
        public static Guid Gabu => new Guid("b73244fb2df84cd583300f6b70d68002");
        public static Guid Kururincho => new Guid("b73244fb2df84cd583300f6b70d68003");
        public static Guid Dock => new Guid("b73244fb2df84cd583300f6b70d68004");
        public static Guid Trigger => new Guid("b73244fb2df84cd583300f6b70d68005");
        public static Guid SideSwitch => new Guid("b73244fb2df84cd583300f6b70d68006");
    }

    public class ToyHackBLE : IDisposable
    {
        public static Guid AdvertiseUUID => new Guid("36b50eb130c741a487a8b250e30fb15d");
        public static Guid ToyHackServiceUUID => new Guid("36b50eb130c741a487a8b250e30fc000");

        public static Guid ModuleNameUUID => new Guid("36b50eb130c741a487a8b250e30fc001");
        public static Guid LibraryNameUUID => new Guid("36b50eb130c741a487a8b250e30fc002");

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
                    ToyHackService = (await device.GetGattServicesForUuidAsync(GaburevolverUUIDs.Service)).Services.First();
                    break;
                case "Minityra":
                    ToyHackService = (await device.GetGattServicesForUuidAsync(MinityraUUIDs.Service)).Services.First();
                    break;
                case "Yokai Watch":
                    ToyHackService = (await device.GetGattServicesForUuidAsync(YokaiWatchUUIDs.Service)).Services.First();
                    break;
            }
            ToyHackCharacteristics = (await ToyHackService.GetCharacteristicsAsync()).Characteristics;
        }

        public void WriteUByte(byte value, Guid characteristicGuid)
        {
            var array = BitConverter.GetBytes(value);
            WriteBytes(array, characteristicGuid);
        }

        public void WriteUShortAsBE(ushort value, Guid characteristicGuid)
        {
            var array = BitConverter.GetBytes(value);
            if (BitConverter.IsLittleEndian)
            {
                // The value should be transmit in big endian
                Array.Reverse(array);
            }

            WriteBytes(array, characteristicGuid);
        }

        public async void WriteBytes(byte[] array, Guid characteristicGuid)
        {
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
