using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ToyHack
{
    static class Program
    {
        /// <summary>
        /// アプリケーションのメイン エントリ ポイントです。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            ToyHackBLE ble;
            using(var adv = new Advertising())
            {
                if (adv.ShowDialog() == DialogResult.Cancel)
                {
                    return;
                }
                ble = adv.BLE;
            }

            Form mainForm = null;
            switch (ble.ModuleName)
            {
                case "Gaburevolver":
                    mainForm = new GaburevolverConsole(ble);
                    break;

                case "Minityra":
                    mainForm = new MinityraConsole(ble);
                    break;

                case "Yokai Watch":
                    mainForm = new YokaiWatchConsole(ble);
                    break;

                default:
                    MessageBox.Show("未対応のサービス（" + ble.ModuleName + "）", "ToyHack", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
            }
            Application.Run(mainForm);
        }
    }
}
