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

            Application.Run(new YokaiWatchConsole(ble));
        }
    }
}
