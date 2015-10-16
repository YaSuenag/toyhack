#ifndef JUDENCHI_H
#define JUDENCHI_H

typedef struct{
  const char *name;
  unsigned char pattern;
} TJudenchi;


/*
 * Judenchi pin assign.
 * This bitpattern starts with top-left in Judenchi switch.
 *
 * See also (in Japanese):
 * http://page.mixi.jp/run_page_apps.pl?appParams=%7B%22q%22%3A%22view_diary%22%2C%22diary_id%22%3A%22681392%22%7D&module_id=87072&page_id=16516
 */
TJudenchi judenchi_list[] = {
                    {(const char *)"ｶﾞﾌﾞﾃｨﾗ",                0x2f}, // 0b101111
                    {(const char *)"ﾊﾟﾗｻｶﾞﾝ",                0x0f}, // 0b001111
                    {(const char *)"ｽﾃｺﾞｯﾁ",                 0x2b}, // 0b101011
                    {(const char *)"ｻﾞｸﾄﾙ",                  0x2a}, // 0b101010
                    {(const char *)"ﾄﾞﾘｹﾗ",                  0x2e}, // 0b101110
                    {(const char *)"ﾌﾟﾃﾗｺﾞｰﾄﾞﾝ",             0x0e}, // 0b001110
                    {(const char *)"ｱﾝｷﾄﾞﾝ",                 0x0b}, // 0b001011
                    {(const char *)"ﾌﾞﾝﾊﾟｯｷｰ",               0x0a}, // 0b001010
                    {(const char *)"ﾌﾟﾚｽﾞｵﾝ",                0x27}, // 0b100111
                    {(const char *)"ﾌﾞﾗｷﾞｶﾞｽ",               0x23}, // 0b100011
                    {(const char *)"ﾃﾞｨﾉﾁｪｲｻｰ",              0x22}, // 0b100010
                    {(const char *)"ﾃﾞｨﾉｽｸﾞﾗﾝﾀﾞｰ",           0x07}, // 0b000111
                    {(const char *)"ｹﾝﾄﾛｽﾊﾟｲｶｰ",             0x03}, // 0b000011
                    {(const char *)"ｽﾃｨﾒﾛ",                  0x02}, // 0b000010
                    {(const char *)"ｱﾛﾒﾗｽ",                  0x06}, // 0b000110
                    {(const char *)"ﾋﾞﾖﾝｽﾓ",                 0x28}, // 0b101000
                    {(const char *)"ｵﾋﾞﾗｯﾌﾟｰ",               0x2d}, // 0b101101
                    {(const char *)"ｲｹﾞﾗﾉﾄﾞﾝ",               0x29}, // 0b101001
                    {(const char *)"ﾄﾍﾟﾗﾝﾀﾞ",                0x2c}, // 0b101100
                    {(const char *)"ｸﾞﾙﾓﾅｲﾄ",                0x0d}, // 0b001101
                    {(const char *)"ｱｰｹﾉﾛﾝ",                 0x09}, // 0b001001
                    {(const char *)"ﾌﾟｸﾌﾟﾄﾙ",                0x08}, // 0b001000
                    {(const char *)"ﾌﾀﾊﾞｲﾝ",                 0x0c}, // 0b001100
                    {(const char *)"ﾄﾊﾞｽﾋﾟﾉ",                0x26}, // 0b100110
                    {(const char *)"ｾﾞﾝｼﾞｭｳﾃﾞﾝﾁ",            0x20}, // 0b100000
                    {(const char *)"ﾃｨﾗﾉｻｳﾙｽ - ﾊﾟｷｹﾌｧﾛｻｳﾙｽ", 0x05}, // 0b000101
                    {(const char *)"ﾃﾞｨﾗﾉｻｳﾙｽ - ﾄﾘｹﾗﾄﾌﾟｽ",   0x01}, // 0b000001
                    {(const char *)"ｷｮｳﾘｭｳｼﾞｬｰ",             0x04}, // 0b000100
                    {(const char *)"ｺﾞﾚﾝｼﾞｬｰ",               0x1c}, // 0b011100
                    {(const char *)"ﾊﾞﾄﾙﾌｨｰﾊﾞｰJ",            0x19}, // 0b011001
                    {(const char *)"ｻﾝﾊﾞﾙｶﾝ",                0x1d}, // 0b011101
                    {(const char *)"ｼﾞｭｳﾚﾝｼﾞｬｰ",             0x38}, // 0b111000
                    {(const char *)"ﾀﾞｲﾚﾝｼﾞｬｰ",              0x3c}, // 0b111100
                    {(const char *)"ｶｸﾚﾝｼﾞｬｰ",               0x39}, // 0b111001
                    {(const char *)"ｵｰﾚﾝｼﾞｬｰ",               0x3d}, // 0b111101
                    {(const char *)"ｶｰﾚﾝｼﾞｬｰ",               0x12}, // 0b010010
                    {(const char *)"ﾒｶﾞﾚﾝｼﾞｬｰ",              0x16}, // 0b010110
                    {(const char *)"ｷﾞﾝｶﾞﾏﾝ",                0x13}, // 0b010011
                    {(const char *)"ｺﾞｰｺﾞｰﾌｧｲﾌﾞ",            0x17}, // 0b010111
                    {(const char *)"ﾀｲﾑﾚﾝｼﾞｬｰ",              0x18}, // 0b011000
                    {(const char *)"ｶﾞｵﾚﾝｼﾞｬｰ",              0x32}, // 0b110010
                    {(const char *)"ﾊﾘｹﾝｼﾞｬｰ",               0x36}, // 0b110110
                    {(const char *)"ｱﾊﾞﾚﾝｼﾞｬｰ",              0x33}, // 0b110011
                    {(const char *)"ﾃﾞｶﾚﾝｼﾞｬｰ",              0x37}, // 0b110111
                    {(const char *)"ﾏｼﾞﾚﾝｼﾞｬｰ",              0x1a}, // 0b011010
                    {(const char *)"ﾎﾞｳｹﾝｼﾞｬｰ",              0x1e}, // 0b011110
                    {(const char *)"ｹﾞｷﾚﾝｼﾞｬｰ",              0x1b}, // 0b011011
                    {(const char *)"ｺﾞｰｵﾝｼﾞｬｰ",              0x1f}, // 0b011111
                    {(const char *)"ｼﾝｹﾝｼﾞｬｰ",               0x3a}, // 0b111010
                    {(const char *)"ｺﾞｾｲｼﾞｬｰ",               0x3e}, // 0b111110
                    {(const char *)"ｺﾞｰｶｲｼﾞｬｰ",              0x3b}, // 0b111011
                    {(const char *)"ｺﾞｰﾊﾞｽﾀｰｽﾞ",             0x3f}, // 0b111111
                    {(const char *)"ｾﾞﾝｾﾝﾀｲ",                0x10}, // 0b010000
                    {(const char *)"ｵｰﾊﾞｰﾁｬｰｼﾞ",             0x21}, // 0b100001
                    {(const char *)"ｵｰﾊﾞｰﾁｬｰｼﾞ",             0x24}, // 0b100100
                    {(const char *)"ｵｰﾊﾞｰﾁｬｰｼﾞ",             0x25}, // 0b100101
                    {(const char *)"ﾜﾗｲｺﾞｴ",                 0x15}, // 0b010101
                    {(const char *)"ﾜﾗｲｺﾞｴ",                 0x35}, // 0b110101
                    {(const char *)"ﾜﾗｲｺﾞｴ",                 0x30}, // 0b110000
                    {(const char *)"ﾜﾗｲｺﾞｴ",                 0x38}, // 0b111000
                    {(const char *)"ﾜﾗｲｺﾞｴ",                 0x14}, // 0b010100
                    {(const char *)"ﾜﾗｲｺﾞｴ",                 0x11}, // 0b010001
                    {(const char *)"ﾜﾗｲｺﾞｴ",                 0x31}  // 0b110001
};


#define JUDENCHI_MAX_ID (int)(sizeof(judenchi_list) / sizeof(TJudenchi))

#define ID_ISIN(id) (((id) >= -1) && ((id) < JUDENCHI_MAX_ID))


#endif /* JUDENCHI_H */
