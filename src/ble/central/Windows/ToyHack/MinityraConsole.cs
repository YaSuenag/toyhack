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
    public partial class MinityraConsole : Form
    {
        private static byte MODE_OVERCHARGE => 0x1;
        private static byte MODE_CARNIVAL => 0x2;

        private readonly ToyHackBLE BLE;

        public MinityraConsole(ToyHackBLE ble)
        {
            InitializeComponent();
            BLE = ble;
        }

        private void MinityraConsole_Load(object sender, EventArgs e)
        {
            JudenchiSocket.Items.Add("<未セット>");
            JudenchiSocket.Items.AddRange(Judenchi.JUDENCHIES
                                                  .Select(j => j.Name)
                                                  .ToArray());
        }

        private void JudenchiSocket_SelectedIndexChanged(object sender, EventArgs e)
        {
            BLE.WriteUByte((byte)(JudenchiSocket.SelectedIndex - 1), MinityraUUIDs.SetJudenchi);
        }

        private void GabuButton_Click(object sender, EventArgs e)
        {
            BLE.WriteUByte(0, MinityraUUIDs.Gabu);
        }

        private void Mode_SelectedIndexChanged(object sender, EventArgs e)
        {
            BLE.WriteUByte((Mode.SelectedIndex == 0) ? MODE_OVERCHARGE : MODE_CARNIVAL, MinityraUUIDs.Kururincho);
        }

        private void Trigger_Click(object sender, EventArgs e)
        {
            BLE.WriteUByte(0, MinityraUUIDs.Trigger);
        }

        private void Dock_Click(object sender, EventArgs e)
        {
            if(Dock.Text == "合体")
            {
                BLE.WriteUByte(1, MinityraUUIDs.Dock);
                Dock.Text = "解除";
            }
            else
            {
                BLE.WriteUByte(0, MinityraUUIDs.Dock);
                Dock.Text = "合体";
            }
        }

        private void SideSwitch_Click(object sender, EventArgs e)
        {
            BLE.WriteUByte(0, MinityraUUIDs.SideSwitch);
        }
    }
}
