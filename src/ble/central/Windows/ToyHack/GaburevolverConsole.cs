using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ToyHack
{
    public partial class GaburevolverConsole : Form
    {
        private readonly ToyHackBLE BLE;

        public GaburevolverConsole(ToyHackBLE ble)
        {
            InitializeComponent();
            BLE = ble;
        }

        private void GaburevolverConsole_Load(object sender, EventArgs e)
        {
            string[] names = Judenchi.JUDENCHIES
                                     .Select(j => j.Name)
                                     .ToArray();

            UpperSocket.Items.Add("<未セット>");
            UpperSocket.Items.AddRange(names);
            UpperSocket.SelectedIndex = 0;

            LowerSocket.Items.Add("<未セット>");
            LowerSocket.Items.AddRange(names);
            LowerSocket.SelectedIndex = 0;
        }

        private void SetterButton_Click(object sender, EventArgs e)
        {
            if(SetterButton.Text == "オープン")
            {
                BLE.WriteUByte(0, GaburevolverUUIDs.OpenSetter);
                SetterButton.Text = "クローズ";
            }
            else
            {
                BLE.WriteUByte(0, GaburevolverUUIDs.CloseSetter);
                SetterButton.Text = "オープン";
            }
        }

        private void JudenchiSetButton_Click(object sender, EventArgs e)
        {
            byte[] array = { (byte)(LowerSocket.SelectedIndex - 1), (byte)(UpperSocket.SelectedIndex - 1) };
            BLE.WriteBytes(array, GaburevolverUUIDs.SetJudenchi);
        }

        private void RotateButton_Click(object sender, EventArgs e)
        {
            BLE.WriteUByte(0, GaburevolverUUIDs.Rotate);
        }

        private void TriggerButton_Click(object sender, EventArgs e)
        {
            BLE.WriteUByte(0, GaburevolverUUIDs.Trigger);
        }

        private void MinityraButton_Click(object sender, EventArgs e)
        {
            if (SetterButton.Text == "ミニティラ合体")
            {
                BLE.WriteUByte(0, GaburevolverUUIDs.DockMinityra);
                SetterButton.Text = "ミニティラ解除";
            }
            else
            {
                BLE.WriteUByte(0, GaburevolverUUIDs.UndockMinityra);
                SetterButton.Text = "ミニティラ合体";
            }
        }

        private void GaburicariburButton_Click(object sender, EventArgs e)
        {
            if (SetterButton.Text == "ガブリカリバー合体")
            {
                BLE.WriteUByte(0, GaburevolverUUIDs.DockGaburicalibur);
                SetterButton.Text = "ガブリカリバー解除";
            }
            else
            {
                BLE.WriteUByte(0, GaburevolverUUIDs.UndockGaburicalibur);
                SetterButton.Text = "ガブリカリバー合体";
            }
        }
    }
}
