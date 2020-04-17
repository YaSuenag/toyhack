using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections.Immutable;

namespace ToyHack
{
    public struct Judenchi
    {
        public string Name { get; }
        public byte Pattern { get; }

        public Judenchi(string Name, byte Pattern)
        {
            this.Name = Name;
            this.Pattern = Pattern;
        }

        // $ grep '{(const char' judenchi.h | sed -e 's/^.\+\(".\+"\), \+\(0x[0-9a-f]\+\).\+$/new Judenchi(\1, \2),/g'
        public static readonly ImmutableArray<Judenchi> JUDENCHIES = ImmutableArray.Create(
            new Judenchi("ガブティラ", 0x2f),
            new Judenchi("パラサガン", 0x0f),
            new Judenchi("ステゴッチ", 0x2b),
            new Judenchi("ザクトル", 0x2a),
            new Judenchi("ドリケラ", 0x2e),
            new Judenchi("プテラゴードン", 0x0e),
            new Judenchi("アンキドン", 0x0b),
            new Judenchi("ブンパッキー", 0x0a),
            new Judenchi("プレズオン", 0x27),
            new Judenchi("ブラギガス", 0x23),
            new Judenchi("ディノチェイサー", 0x22),
            new Judenchi("ディノスグランダー", 0x07),
            new Judenchi("ケントロスパイカー", 0x03),
            new Judenchi("スティメロ", 0x02),
            new Judenchi("アロメラス", 0x06),
            new Judenchi("ビヨンスモ", 0x28),
            new Judenchi("オビラップー", 0x2d),
            new Judenchi("イゲラノドン", 0x29),
            new Judenchi("トペランダ", 0x2c),
            new Judenchi("グルモナイト", 0x0d),
            new Judenchi("アーケノロン", 0x09),
            new Judenchi("プクプトル", 0x08),
            new Judenchi("フタバイン", 0x0c),
            new Judenchi("トバスピノ", 0x26),
            new Judenchi("全獣電池", 0x20),
            new Judenchi("ティラノサウルス - パキケファロサウルス", 0x05),
            new Judenchi("ディラノサウルス - トリケラトプス", 0x01),
            new Judenchi("キョウリュウジャー", 0x04),
            new Judenchi("ゴレンジャー", 0x1c),
            new Judenchi("バトルフィーバーJ", 0x19),
            new Judenchi("サンバルカン", 0x1d),
            new Judenchi("ジュウレンジャー", 0x38),
            new Judenchi("ダイレンジャー", 0x3c),
            new Judenchi("カクレンジャー", 0x39),
            new Judenchi("オーレンジャー", 0x3d),
            new Judenchi("カーレンジャー", 0x12),
            new Judenchi("メガレンジャー", 0x16),
            new Judenchi("ギンガマン", 0x13),
            new Judenchi("ゴーゴーファイブ", 0x17),
            new Judenchi("タイムレンジャー", 0x18),
            new Judenchi("ガオレンジャー", 0x32),
            new Judenchi("ハリケンジャー", 0x36),
            new Judenchi("アバレンジャー", 0x33),
            new Judenchi("デカレンジャー", 0x37),
            new Judenchi("マジレンジャー", 0x1a),
            new Judenchi("ボウケンジャー", 0x1e),
            new Judenchi("ゲキレンジャー", 0x1b),
            new Judenchi("ゴーオンジャー", 0x1f),
            new Judenchi("シンケンジャー", 0x3a),
            new Judenchi("ゴセイジャー", 0x3e),
            new Judenchi("ゴーカイジャー", 0x3b),
            new Judenchi("ゴーバスターズ", 0x3f),
            new Judenchi("全戦隊", 0x10),
            new Judenchi("オーバーチャージ", 0x21),
            new Judenchi("オーバーチャージ", 0x24),
            new Judenchi("カーニバル", 0x25),
            new Judenchi("笑い声", 0x15),
            new Judenchi("笑い声", 0x35),
            new Judenchi("ビクトリー", 0x30),
            new Judenchi("笑い声", 0x38),
            new Judenchi("笑い声", 0x14),
            new Judenchi("マキシマム", 0x11),
            new Judenchi("笑い声", 0x31)
        );
    }
}
