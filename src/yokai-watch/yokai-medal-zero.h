#ifndef YOKAI_MEDAL_ZERO_H
#define YOKAI_MEDAL_ZERO_H

#include "yokai-medal-common.h"


/*
 * Yokai-Medal ZERO pin assignment
 *
 * See also (in Japanese):
 * http://yokai.kaathemachine.com/2015/04/%E9%9B%B6%E5%BC%8Fz%E3%83%A1%E3%83%80%E3%83%AB%E3%83%BB%E5%8F%A4%E5%85%B8%E3%83%A1%E3%83%80%E3%83%AB%E3%81%AE%E9%9F%B3%E5%A3%B0%E3%83%91%E3%82%BF%E3%83%BC%E3%83%B3%E4%B8%80%E8%A6%A7%E8%A1%A8/
 */
TMedal medal_list[] = {
  {(const char *)"ロボりゅうくん", 0x153a}, // 0b0001010100111010
  {(const char *)"スイカニャン", 0x154a}, // 0b0001010101001010
  {(const char *)"メロンニャン", 0x156a}, // 0b0001010101101010
  {(const char *)"しゅらコマ", 0x157a}, // 0b0001010101111010
  {(const char *)"キウイニャン", 0x158a}, // 0b0001010110001010
  {(const char *)"山吹鬼", 0x159a}, // 0b0001010110011010
  {(const char *)"イケメン犬", 0x15ba}, // 0b0001010110111010
  {(const char *)"花さか爺", 0x15ca}, // 0b0001010111001010
  {(const char *)"ブシニャン", 0x15da}, // 0b0001010111011010
  {(const char *)"りゅうくん", 0x15ea}, // 0b0001010111101010
  {(const char *)"イチゴニャン", 0x15fa}, // 0b0001010111111010
  {(const char *)"ジコチュウ", 0x357a}, // 0b0011010101111010
  {(const char *)"スティーブジョーズ", 0x359a}, // 0b0011010110011010
  {(const char *)"イザナミ", 0x35ba}, // 0b0011010110111010
  {(const char *)"アペリカン", 0x35ca}, // 0b0011010111001010
  {(const char *)"女郎蜘蛛", 0x35da}, // 0b0011010111011010
  {(const char *)"一角", 0x35ea}, // 0b0011010111101010
  {(const char *)"Mr.ムービーン", 0x35fa}, // 0b0011010111111010
  {(const char *)"コマさん 前略お母ちゃん", 0x651a}, // 0b0110010100011010
  {(const char *)"コマじろう にーさんスゲーずら", 0x653a}, // 0b0110010100111010
  {(const char *)"天狗", 0x658a}, // 0b0110010110001010
  {(const char *)"コマさん 今日からともだちずら", 0x659a}, // 0b0110010110011010
  {(const char *)"ジバニャン ニャーケービー", 0x65ba}, // 0b0110010110111010
  {(const char *)"ダークニャン 地獄におちニャン", 0x65ca}, // 0b0110010111001010
  {(const char *)"ジバニャン 百烈肉球", 0x65da}, // 0b0110010111011010
  {(const char *)"ヒキコウモリ", 0x65ea}, // 0b0110010111101010
  {(const char *)"トゲニャン", 0x65fa}, // 0b0110010111111010
  {(const char *)"ブチニャン　ウイッス", 0x751a}, // 0b0111010100011010
  {(const char *)"ブリー隊長 イチニッサンホー", 0x752a}, // 0b0111010100101010
  {(const char *)"なんかい", 0x753a}, // 0b0111010100111010
  {(const char *)"コールのみ", 0x754a}, // 0b0111010101001010
  {(const char *)"はかい", 0x756a}, // 0b0111010101101010
  {(const char *)"あかまる", 0x758a}, // 0b0111010110001010
  {(const char *)"ゴーカイ", 0x759a}, // 0b0111010110011010
  {(const char *)"泥太坊怪", 0x75ba}, // 0b0111010110111010
  {(const char *)"不快", 0x75ca}, // 0b0111010111001010
  {(const char *)"あかなめ怪", 0x75da}, // 0b0111010111011010
  {(const char *)"ノガッパ クワッ", 0x75ea}, // 0b0111010111101010
  {(const char *)"やっかい", 0x75fa}, // 0b0111010111111010
  {(const char *)"ロボガッパ", 0x85ba}, // 0b1000010110111010
  {(const char *)"ロボメン犬", 0x85da}, // 0b1000010111011010
  {(const char *)"ロボノコ", 0x85ea}, // 0b1000010111101010
  {(const char *)"獅子まる", 0xc12a}, // 0b1100000100101010
  {(const char *)"かたづ家来", 0xc13a}, // 0b1100000100111010
  {(const char *)"おこ武者", 0xc14a}, // 0b1100000101001010
  {(const char *)"おにぎり侍", 0xc16a}, // 0b1100000101101010
  {(const char *)"あかなめ", 0xc17a}, // 0b1100000101111010
  {(const char *)"泥田坊", 0xc18a}, // 0b1100000110001010
  {(const char *)"ブリー隊長", 0xc19a}, // 0b1100000110011010
  {(const char *)"アライ魔将", 0xc1ba}, // 0b1100000110111010
  {(const char *)"フユニャン", 0xc1da}, // 0b1100000111011010
  {(const char *)"万尾獅子", 0xc1ea}, // 0b1100000111101010
  {(const char *)"焼きおに斬り", 0xc1fa}, // 0b1100000111111010
  {(const char *)"鬼食い", 0xc21a}, // 0b1100001000011010
  {(const char *)"さかさ傘", 0xc23a}, // 0b1100001000111010
  {(const char *)"こえんら", 0xc24a}, // 0b1100001001001010
  {(const char *)"化け草履", 0xc26a}, // 0b1100001001101010
  {(const char *)"のっぺらぼう", 0xc27a}, // 0b1100001001111010
  {(const char *)"一旦ゴメン", 0xc28a}, // 0b1100001010001010
  {(const char *)"U.S.O", 0xc29a}, // 0b1100001010011010
  {(const char *)"メゾンドワスレ", 0xc2ba}, // 0b1100001010111010
  {(const char *)"えんらえんら", 0xc2da}, // 0b1100001011011010
  {(const char *)"おでんじん", 0xc2ea}, // 0b1100001011101010
  {(const char *)"あやまり倒し", 0xc2fa}, // 0b1100001011111010
  {(const char *)"うんがい三面鏡", 0xc31a}, // 0b1100001100011010
  {(const char *)"ぬえ", 0xc32a}, // 0b1100001100101010
  {(const char *)"ドキ土器", 0xc34a}, // 0b1100001101001010
  {(const char *)"うらや飯", 0xc36a}, // 0b1100001101101010
  {(const char *)"迷い車", 0xc37a}, // 0b1100001101111010
  {(const char *)"雷蔵", 0xc38a}, // 0b1100001110001010
  {(const char *)"モノマネキン", 0xc39a}, // 0b1100001110011010
  {(const char *)"あせっか鬼", 0xc3ba}, // 0b1100001110111010
  {(const char *)"だっせんしゃ", 0xc3da}, // 0b1100001111011010
  {(const char *)"プライ丼", 0xc3ea}, // 0b1100001111101010
  {(const char *)"ヒライ神", 0xc3fa}, // 0b1100001111111010
  {(const char *)"ガマンモス", 0xc41a}, // 0b1100010000011010
  {(const char *)"百々目鬼", 0xc42a}, // 0b1100010000101010
  {(const char *)"大ガマ", 0xc43a}, // 0b1100010000111010
  {(const char *)"一つ目小僧", 0xc46a}, // 0b1100010001101010
  {(const char *)"びきゃく", 0xc47a}, // 0b1100010001111010
  {(const char *)"つらがわり", 0xc48a}, // 0b1100010010001010
  {(const char *)"雨女", 0xc49a}, // 0b1100010010011010
  {(const char *)"ばくそく", 0xc4ba}, // 0b1100010010111010
  {(const char *)"おバく様", 0xc4da}, // 0b1100010011011010
  {(const char *)"河童", 0xc4ea}, // 0b1100010011101010
  {(const char *)"マスターニャーダ", 0xc4fa}, // 0b1100010011111010
  {(const char *)"きらめき鬼", 0xc51a}, // 0b1100010100011010
  {(const char *)"水虎", 0xc52a}, // 0b1100010100101010
  {(const char *)"大やもり", 0xc54a}, // 0b1100010101001010
  {(const char *)"いのちとり", 0xc56a}, // 0b1100010101101010
  {(const char *)"風魔猿", 0xc58a}, // 0b1100010110001010
  {(const char *)"こまじろう ゲラゲラポンモンゲー", 0xc5da}, // 0b1100010111011010
  {(const char *)"コマさん ゲラゲラゲラポーずら", 0xc5ea}, // 0b1100010111101010
  {(const char *)"キズナメコ", 0xc61a}, // 0b1100011000011010
  {(const char *)"から傘お化け", 0xc62a}, // 0b1100011000101010
  {(const char *)"砂夫", 0xc63a}, // 0b1100011000111010
  {(const char *)"くだん", 0xc64a}, // 0b1100011001001010
  {(const char *)"ざしきわらし", 0xc67a}, // 0b1100011001111010
  {(const char *)"晴れ男", 0xc69a}, // 0b1100011010011010
  {(const char *)"ワカメ☆スター", 0xc6ba}, // 0b1100011010111010
  {(const char *)"キズナース", 0xc6da}, // 0b1100011011011010
  {(const char *)"大山砂夫", 0xc6ea}, // 0b1100011011101010
  {(const char *)"から傘魔人", 0xc6fa}, // 0b1100011011111010
  {(const char *)"ざしきわら神", 0xc71a}, // 0b1100011100011010
  {(const char *)"お金ナイダー", 0xc72a}, // 0b1100011100101010
  {(const char *)"大くだん", 0xc73a}, // 0b1100011100111010
  {(const char *)"麒麟", 0xc74a}, // 0b1100011101001010
  {(const char *)"TETSUYA", 0xc76a}, // 0b1100011101101010
  {(const char *)"かりパックン", 0xc78a}, // 0b1100011110001010
  {(const char *)"草くいおとこ", 0xc79a}, // 0b1100011110011010
  {(const char *)"まてんし", 0xc7ba}, // 0b1100011110111010
  {(const char *)"ひとまか仙人", 0xc7da}, // 0b1100011111011010
  {(const char *)"りもこんかくし", 0xc7ea}, // 0b1100011111101010
  {(const char *)"ミツマタノヅチ", 0xc7fa}, // 0b1100011111111010
  {(const char *)"リー夫人", 0xc81a}, // 0b1100100000011010
  {(const char *)"ガブニャン", 0xc82a}, // 0b1100100000101010
  {(const char *)"KANTETSU", 0xc83a}, // 0b1100100000111010
  {(const char *)"肉くい男", 0xc84a}, // 0b1100100001001010
  {(const char *)"泥ボックン", 0xc86a}, // 0b1100100001101010
  {(const char *)"どんどろ", 0xc87a}, // 0b1100100001111010
  {(const char *)"けうけげん", 0xc89a}, // 0b1100100010011010
  {(const char *)"おともらし", 0xc8ba}, // 0b1100100010111010
  {(const char *)"認MEN", 0xc8da}, // 0b1100100011011010
  {(const char *)"じがじぃさん", 0xc8ea}, // 0b1100100011101010
  {(const char *)"花子さん", 0xc8fa}, // 0b1100100011111010
  {(const char *)"のらりくらり", 0xc91a}, // 0b1100100100011010
  {(const char *)"ぶんぶん鳥", 0xc92a}, // 0b1100100100101010
  {(const char *)"のぼせトンマン", 0xc93a}, // 0b1100100100111010
  {(const char *)"爆音ならし", 0xc94a}, // 0b1100100101001010
  {(const char *)"ふさふさん", 0xc96a}, // 0b1100100101101010
  {(const char *)"呪野花子", 0xc97a}, // 0b1100100101111010
  {(const char *)"土蜘蛛", 0xc98a}, // 0b1100100110001010
  {(const char *)"ケマモン", 0xc9ba}, // 0b1100100110111010
  {(const char *)"ねちがえる", 0xc9da}, // 0b1100100111011010
  {(const char *)"からみぞん", 0xc9ea}, // 0b1100100111101010
  {(const char *)"おもいだスッポン", 0xc9fa}, // 0b1100100111111010
  {(const char *)"つられたろう丸", 0xcb1a}, // 0b1100101100011010
  {(const char *)"ムカムカデ", 0xcb2a}, // 0b1100101100101010
  {(const char *)"にんぎょ", 0xcb3a}, // 0b1100101100111010
  {(const char *)"ろくろ首", 0xcb4a}, // 0b1100101101001010
  {(const char *)"ホリュウ", 0xcb6a}, // 0b1100101101101010
  {(const char *)"激ドラゴン", 0xcb7a}, // 0b1100101101111010
  {(const char *)"おもいだ神", 0xcb8a}, // 0b1100101110001010
  {(const char *)"こんがらギャル", 0xcb9a}, // 0b1100101110011010
  {(const char *)"八百比丘尼", 0xcbda}, // 0b1100101111011010
  {(const char *)"ネタバレリーナ", 0xcbea}, // 0b1100101111101010
  {(const char *)"うんちく魔", 0xcbfa}, // 0b1100101111111010
  {(const char *)"やまタン", 0xcd1a}, // 0b1100110100011010
  {(const char *)"ジバニャン コマニャチ", 0xd9ca}, // 0b1101100111001010
  {(const char *)"ジバニャン ニャイーン", 0xd9ea}, // 0b1101100111101010
  {(const char *)"ジバニャン ニョエー", 0xd9fa}, // 0b1101100111111010
  {(const char *)"フユニャン", 0xdb1a}, // 0b1101101100011010
  {(const char *)"おめでとうございます", 0xdb2a}, // 0b1101101100101010
  {(const char *)"すごいですねやるもんですね", 0xdb3a}, // 0b1101101100111010
  {(const char *)"コロコロコミック", 0xdb4a}, // 0b1101101101001010
  {(const char *)"コールのみ", 0xdb6a}, // 0b1101101101101010
  {(const char *)"コールのみ", 0xdb7a}, // 0b1101101101111010
  {(const char *)"コールのみ", 0xdb8a}, // 0b1101101110001010
  {(const char *)"コールのみ", 0xdb9a}, // 0b1101101110011010
  {(const char *)"コールのみ", 0xdbca}, // 0b1101101111001010
  {(const char *)"コールのみ", 0xdbea}, // 0b1101101111101010
  {(const char *)"コールのみ", 0xdbfa}, // 0b1101101111111010
  {(const char *)"コールのみ", 0xdc1a}, // 0b1101110000011010
  {(const char *)"コールのみ", 0xdc2a}, // 0b1101110000101010
  {(const char *)"ロボニャン オイ何とか", 0xe51a}, // 0b1110010100011010
  {(const char *)"ドンヨリーヌ モージョーン", 0xe52a}, // 0b1110010100101010
  {(const char *)"ツチノコ キュピーン", 0xe53a}, // 0b1110010100111010
  {(const char *)"ホノボーノ ボーノー", 0xe54a}, // 0b1110010101001010
  {(const char *)"キュウビ", 0xe56a}, // 0b1110010101101010
  {(const char *)"メラメライオン メラメラー", 0xe57a}, // 0b1110010101111010
  {(const char *)"オロチ", 0xe58a}, // 0b1110010110001010
  {(const char *)"ひもじぃ ひーもー", 0xe59a}, // 0b1110010110011010
  {(const char *)"じんめん犬 チクショー", 0xe5ba}, // 0b1110010110111010
  {(const char *)"バクロ婆 ババーン", 0xe5ca}, // 0b1110010111001010
  {(const char *)"コマさん もんげー", 0xe5da}, // 0b1110010111011010
  {(const char *)"セバスチャン", 0xe5fa}, // 0b1110010111111010
  {(const char *)"ブドウニャン", 0xf51a}, // 0b1111010100011010
  {(const char *)"ろくろ首怪", 0xf52a}, // 0b1111010100101010
  {(const char *)"ミカンニャン", 0xf53a}, // 0b1111010100111010
  {(const char *)"にんぎょ怪", 0xf54a}, // 0b1111010101001010
  {(const char *)"くだん怪", 0xf56a}, // 0b1111010101101010
  {(const char *)"から傘お化け怪", 0xf57a}, // 0b1111010101111010
  {(const char *)"けうけげん怪", 0xf58a}, // 0b1111010110001010
  {(const char *)"ロボG", 0xf59a}, // 0b1111010110011010
  {(const char *)"河童怪", 0xf5ba}, // 0b1111010110111010
  {(const char *)"ざしきわらし怪", 0xf5ca}, // 0b1111010111001010
  {(const char *)"えんらえんら怪", 0xf5da}, // 0b1111010111011010
  {(const char *)"ロボコマ おどろきずらモンゲー", 0xf5ea}, // 0b1111010111101010
};

#define MEDAL_MAX_ID (int)(sizeof(medal_list) / sizeof(TMedal))

#define ID_ISIN(id) (((id) >= -1) && ((id) < MEDAL_MAX_ID))

#endif /* YOKAI_MEDAL_ZERO_H */