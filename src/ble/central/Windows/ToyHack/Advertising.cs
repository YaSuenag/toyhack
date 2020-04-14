using System;
using System.Windows.Forms;
using Windows.Devices.Bluetooth.Advertisement;

namespace ToyHack
{
    public partial class Advertising : Form
    {

        private BluetoothLEAdvertisementWatcher adv;

        private ToyHackBLE _ble;

        public ToyHackBLE BLE => _ble;

        public Advertising()
        {
            InitializeComponent();
            _ble = null;
        }

        private void Advertise_Received(BluetoothLEAdvertisementWatcher sender, BluetoothLEAdvertisementReceivedEventArgs args)
        {
            _ble = new ToyHackBLE(args.BluetoothAddress);
            adv.Stop();
        }

        private void Advertise_Stopped(BluetoothLEAdvertisementWatcher sender, BluetoothLEAdvertisementWatcherStoppedEventArgs args)
        {
            Invoke(new Action(Close));
        }

        private void Advertising_Load(object sender, EventArgs e)
        {
            adv = new BluetoothLEAdvertisementWatcher();
            adv.AdvertisementFilter.Advertisement.ServiceUuids.Add(ToyHackBLE.AdvertiseUUID);
            adv.Received += Advertise_Received;
            adv.Stopped += Advertise_Stopped;
            adv.Start();
        }

        private void CancelButton_Click(object sender, EventArgs e)
        {
            adv.Stop();
        }

        private void Advertising_FormClosing(object sender, FormClosingEventArgs e)
        {
            DialogResult = _ble != null ? DialogResult.OK : DialogResult.Cancel;
        }
    }
}
