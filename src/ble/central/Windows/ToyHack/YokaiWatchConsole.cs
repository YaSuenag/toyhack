using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace ToyHack
{
    public partial class YokaiWatchConsole : Form
    {
        private readonly ToyHackBLE BLE;

        public YokaiWatchConsole(ToyHackBLE ble)
        {
            InitializeComponent();
            BLE = ble;
        }

        private void YokaiWatchConsole_Load(object sender, EventArgs e)
        {
            normalMedalMenu_Click(sender, e);
        }

        private void selectMedal(MedalCategory category)
        {
            medalList.Items.Clear();
            medalList.Items.AddRange(YokaiMedal.MEDALS
                                               .Where(m => (m.Category == category) || (m.Category == MedalCategory.Common))
                                               .Select(m => new ListViewItem(new string[]{ m.Name, m.Pattern.ToString() }, m.Name))
                                               .ToArray());
        }

        private void normalMedalMenu_Click(object sender, EventArgs e)
        {
            selectMedal(MedalCategory.Normal);
        }

        private void zMedalMenu_Click(object sender, EventArgs e)
        {
            selectMedal(MedalCategory.Z);
        }

        private void medalList_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(medalList.SelectedItems.Count == 1)
            {
                BLE.WriteUShortAsBE(Convert.ToUInt16(medalList.SelectedItems[0].SubItems[1].Text), YokaiWatchUUIDs.SetMedal);
            }
            else
            {
                BLE.WriteUByte(0, YokaiWatchUUIDs.EjectMedal);
            }
        }

        private void imageLoadMenu_Click(object sender, EventArgs e)
        {
            if(folderBrowserDialog1.ShowDialog() == DialogResult.OK)
            {
                medalImageList.Images.Clear();
                foreach(var filename in Directory.GetFiles(folderBrowserDialog1.SelectedPath))
                {
                    var basename = Path.GetFileNameWithoutExtension(filename);
                    var image = Image.FromFile(filename);
                    medalImageList.Images.Add(basename, image);
                }
            }
        }
    }
}
