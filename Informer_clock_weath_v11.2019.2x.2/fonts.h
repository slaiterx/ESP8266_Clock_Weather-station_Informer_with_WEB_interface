const uint8_t fonts[] PROGMEM = {8,
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Space
  0x01, 0x5f, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00,  // !
  0x03, 0x07, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00,  // "
  0x05, 0x14, 0x7f, 0x14, 0x7f, 0x14, 0x00, 0x00,  // #
  0x05, 0x24, 0x2a, 0x7f, 0x2a, 0x12, 0x00, 0x00,  // $
  0x05, 0x23, 0x13, 0x08, 0x64, 0x62, 0x00, 0x00,  // %
  0x05, 0x36, 0x49, 0x56, 0x20, 0x50, 0x00, 0x00,  // &
  0x03, 0x08, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00,  // '
  0x03, 0x1c, 0x22, 0x41, 0x00, 0x00, 0x00, 0x00,  // (
  0x03, 0x41, 0x22, 0x1c, 0x00, 0x00, 0x00, 0x00,  // )
  0x05, 0x2a, 0x1c, 0x7f, 0x1c, 0x2a, 0x00, 0x00,  // *
  0x05, 0x08, 0x08, 0x3e, 0x08, 0x08, 0x00, 0x00,  // +
  0x03, 0x80, 0x70, 0x30, 0x00, 0x00, 0x00, 0x00,  // ,
  0x05, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00,  // -
  0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // .
  0x05, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00, 0x00,  // /
  0x05, 0x3e, 0x51, 0x49, 0x45, 0x3e, 0x00, 0x00,  // 0
  0x05, 0x00, 0x42, 0x7f, 0x40, 0x00, 0x00, 0x00,  // 1
  0x05, 0x72, 0x49, 0x49, 0x49, 0x46, 0x00, 0x00,  // 2
  0x05, 0x21, 0x41, 0x49, 0x4d, 0x33, 0x00, 0x00,  // 3
  0x05, 0x18, 0x14, 0x12, 0x7f, 0x10, 0x00, 0x00,  // 4
  0x05, 0x27, 0x45, 0x45, 0x45, 0x39, 0x00, 0x00,  // 5
  0x05, 0x3c, 0x4a, 0x49, 0x49, 0x31, 0x00, 0x00,  // 6
  0x05, 0x41, 0x21, 0x11, 0x09, 0x07, 0x00, 0x00,  // 7
  0x05, 0x36, 0x49, 0x49, 0x49, 0x36, 0x00, 0x00,  // 8
  0x05, 0x46, 0x49, 0x49, 0x29, 0x1e, 0x00, 0x00,  // 9
  0x02, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00,  // :
  0x02, 0x80, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00,  // ;
  0x04, 0x08, 0x14, 0x22, 0x41, 0x00, 0x00, 0x00,  // <
  0x05, 0x14, 0x14, 0x14, 0x14, 0x14, 0x00, 0x00,  // =
  0x04, 0x41, 0x22, 0x14, 0x08, 0x00, 0x00, 0x00,  // >
  0x05, 0x02, 0x01, 0x59, 0x09, 0x06, 0x00, 0x00,  // ?
  0x05, 0x3e, 0x41, 0x5d, 0x59, 0x4e, 0x00, 0x00,  // @
  0x05, 0x7c, 0x12, 0x11, 0x12, 0x7c, 0x00, 0x00,  // A
  0x05, 0x7f, 0x49, 0x49, 0x49, 0x36, 0x00, 0x00,  // B
  0x05, 0x3e, 0x41, 0x41, 0x41, 0x22, 0x00, 0x00,  // C
  0x05, 0x7f, 0x41, 0x41, 0x41, 0x3e, 0x00, 0x00,  // D
  0x05, 0x7f, 0x49, 0x49, 0x49, 0x41, 0x00, 0x00,  // E
  0x05, 0x7f, 0x09, 0x09, 0x09, 0x01, 0x00, 0x00,  // F
  0x05, 0x3e, 0x41, 0x41, 0x51, 0x73, 0x00, 0x00,  // G
  0x05, 0x7f, 0x08, 0x08, 0x08, 0x7f, 0x00, 0x00,  // H
  0x03, 0x41, 0x7f, 0x41, 0x00, 0x00, 0x00, 0x00,  // I
  0x05, 0x20, 0x40, 0x41, 0x3f, 0x01, 0x00, 0x00,  // J
  0x05, 0x7f, 0x08, 0x14, 0x22, 0x41, 0x00, 0x00,  // K
  0x05, 0x7f, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00,  // L
  0x05, 0x7f, 0x02, 0x1c, 0x02, 0x7f, 0x00, 0x00,  // M
  0x05, 0x7f, 0x04, 0x08, 0x10, 0x7f, 0x00, 0x00,  // N
  0x05, 0x3e, 0x41, 0x41, 0x41, 0x3e, 0x00, 0x00,  // O
  0x05, 0x7f, 0x09, 0x09, 0x09, 0x06, 0x00, 0x00,  // P
  0x05, 0x3e, 0x41, 0x51, 0x21, 0x5e, 0x00, 0x00,  // Q
  0x05, 0x7f, 0x09, 0x19, 0x29, 0x46, 0x00, 0x00,  // R
  0x05, 0x26, 0x49, 0x49, 0x49, 0x32, 0x00, 0x00,  // S
  0x05, 0x03, 0x01, 0x7f, 0x01, 0x03, 0x00, 0x00,  // T
  0x05, 0x3f, 0x40, 0x40, 0x40, 0x3f, 0x00, 0x00,  // U
  0x05, 0x1f, 0x20, 0x40, 0x20, 0x1f, 0x00, 0x00,  // V
  0x05, 0x3f, 0x40, 0x38, 0x40, 0x3f, 0x00, 0x00,  // W
  0x05, 0x63, 0x14, 0x08, 0x14, 0x63, 0x00, 0x00,  // X
  0x05, 0x03, 0x04, 0x78, 0x04, 0x03, 0x00, 0x00,  // Y
  0x05, 0x61, 0x51, 0x49, 0x45, 0x43, 0x00, 0x00,  // Z
  0x03, 0x7f, 0x41, 0x41, 0x00, 0x00, 0x00, 0x00,  // [
  0x05, 0x02, 0x04, 0x08, 0x10, 0x20, 0x00, 0x00,  // \'
  0x03, 0x41, 0x41, 0x7f, 0x00, 0x00, 0x00, 0x00,  // ]
  0x05, 0x04, 0x02, 0x01, 0x02, 0x04, 0x00, 0x00,  // ^
  0x05, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00,  // _
  0x02, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,  // `
  0x05, 0x20, 0x54, 0x54, 0x78, 0x40, 0x00, 0x00,  // a
  0x05, 0x7f, 0x28, 0x44, 0x44, 0x38, 0x00, 0x00,  // b
  0x05, 0x38, 0x44, 0x44, 0x44, 0x28, 0x00, 0x00,  // c
  0x05, 0x38, 0x44, 0x44, 0x28, 0x7f, 0x00, 0x00,  // d
  0x05, 0x38, 0x54, 0x54, 0x54, 0x18, 0x00, 0x00,  // e
  0x04, 0x08, 0x7e, 0x09, 0x02, 0x00, 0x00, 0x00,  // f
  0x05, 0x18, 0xa4, 0xa4, 0x9c, 0x78, 0x00, 0x00,  // g
  0x05, 0x7f, 0x08, 0x04, 0x04, 0x78, 0x00, 0x00,  // h
  0x03, 0x44, 0x7d, 0x40, 0x00, 0x00, 0x00, 0x00,  // i
  0x04, 0x40, 0x80, 0x80, 0x7a, 0x00, 0x00, 0x00,  // j
  0x04, 0x7f, 0x10, 0x28, 0x44, 0x00, 0x00, 0x00,  // k
  0x03, 0x41, 0x7f, 0x40, 0x00, 0x00, 0x00, 0x00,  // l
  0x05, 0x7c, 0x04, 0x78, 0x04, 0x78, 0x00, 0x00,  // m
  0x05, 0x7c, 0x08, 0x04, 0x04, 0x78, 0x00, 0x00,  // n
  0x05, 0x38, 0x44, 0x44, 0x44, 0x38, 0x00, 0x00,  // o
  0x05, 0xfc, 0x18, 0x24, 0x24, 0x18, 0x00, 0x00,  // p
  0x05, 0x18, 0x24, 0x24, 0x18, 0xfc, 0x00, 0x00,  // q
  0x05, 0x7c, 0x08, 0x04, 0x04, 0x08, 0x00, 0x00,  // r
  0x05, 0x48, 0x54, 0x54, 0x54, 0x24, 0x00, 0x00,  // s
  0x04, 0x04, 0x3f, 0x44, 0x24, 0x00, 0x00, 0x00,  // t
  0x05, 0x3c, 0x40, 0x40, 0x20, 0x7c, 0x00, 0x00,  // u
  0x05, 0x1c, 0x20, 0x40, 0x20, 0x1c, 0x00, 0x00,  // v
  0x05, 0x3c, 0x40, 0x30, 0x40, 0x3c, 0x00, 0x00,  // w
  0x05, 0x44, 0x28, 0x10, 0x28, 0x44, 0x00, 0x00,  // x
  0x05, 0x4c, 0x90, 0x90, 0x90, 0x7c, 0x00, 0x00,  // y
  0x05, 0x44, 0x64, 0x54, 0x4c, 0x44, 0x00, 0x00,  // z
  0x03, 0x08, 0x36, 0x41, 0x00, 0x00, 0x00, 0x00,  // {
  0x01, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // |
  0x03, 0x41, 0x36, 0x08, 0x00, 0x00, 0x00, 0x00,  // }
  0x05, 0x02, 0x01, 0x02, 0x04, 0x02, 0x00, 0x00,  // ~
  0x05, 0x3c, 0x26, 0x23, 0x26, 0x3c, 0x00, 0x00,  // Hollow Up Arrow
  0x07, 0x0E, 0x1F, 0x3F, 0x7E, 0x3F, 0x1F, 0x0E,  // 200 - heart СЕРЦЕ
  0x07, 0x0E, 0x11, 0x04, 0x7A, 0x04, 0x11, 0x0E,  // 201 - антена точки доступа 
  0x04, 0x06, 0x09, 0x09, 0x06, 0x00, 0x00, 0x00,  // 202 - градус цельсия
  0x05, 0x7E, 0x81, 0x81, 0xC3, 0x42, 0x00, 0x00,  // 203 - C большая
  0x05, 0x3e, 0x49, 0x49, 0x49, 0x22, 0x00, 0x00,  // Є ukr
  0x05, 0x7E, 0x02, 0x02, 0x02, 0x01, 0x00, 0x00,  // Ґ ukr
  0x03, 0x41, 0x7f, 0x41, 0x00, 0x00, 0x00, 0x00,  // I ukr
  0x05, 0x01, 0x40, 0x7E, 0x40, 0x01, 0x00, 0x00,  // Ї ukr
  0x05, 0x04, 0x02, 0x7F, 0x02, 0x04, 0x00, 0x00,  // 210 - стрелка вверх 0 градусов
  0x05, 0x10, 0x20, 0x7F, 0x20, 0x10, 0x00, 0x00,  // 211 - стрелка вниз 180 градусов
  0x05, 0x60, 0xFE, 0xF9, 0xFE, 0x60, 0x00, 0x00,  // 212 - Градусник
  0x05, 0x38, 0x44, 0x43, 0x44, 0x38, 0x00, 0x00,  // 213 - Капелька
  0x06, 0x24, 0x12, 0x12, 0x24, 0x24, 0x12, 0x00,  // 214 - Ветер
  0x05, 0x44, 0x48, 0x5F, 0x48, 0x44, 0x00, 0x00,  // 215 - Давление
  0x07, 0x1C, 0x22, 0x22, 0x24, 0x28, 0x24, 0x18,  // 216 - Облачность
  0x07, 0x3C, 0x42, 0x95, 0xA1, 0x95, 0x42, 0x3C,  // 217 - :)
  0x07, 0x3C, 0x42, 0xA5, 0x91, 0xA5, 0x42, 0x3C,  // 220 - :(
  0x05, 0x14, 0x3E, 0x55, 0x41, 0x22, 0x00, 0x00,  // 221 - Евро
  0x05, 0x14, 0x35, 0x5D, 0x56, 0x14, 0x00, 0x00,  // 222 - Гривна
  0x07, 0x64, 0x54, 0x4C, 0x00, 0x08, 0x7F, 0x04,  // 223 - Злотый
  0x05, 0x38, 0x54, 0x54, 0x44, 0x28, 0x00, 0x00,  // є ukr
  0x04, 0x7c, 0x04, 0x04, 0x02, 0x00, 0x00, 0x00,  // ґ ukr
  0x03, 0x44, 0x7d, 0x40, 0x00, 0x00, 0x00, 0x00,  // i ukr
  0x03, 0x4A, 0x78, 0x42, 0x00, 0x00, 0x00, 0x00,  // ї ukr
  0x07, 0x08, 0x1C, 0x2A, 0x08, 0x08, 0x08, 0x08,  // 230 - Стрелка влево 270 градусов
  0x07, 0x08, 0x08, 0x08, 0x08, 0x2A, 0x1C, 0x08,  // 231 - Стрелка вправо 90 градусов
  0x07, 0x40, 0x20, 0x10, 0x09, 0x05, 0x03, 0x0F,  // 232 - Стрелка 45 градусов
  0x07, 0x01, 0x02, 0x04, 0x48, 0x50, 0x60, 0x78,  // 233 - Стрелка 135 градусов
  0x07, 0x78, 0x60, 0x50, 0x48, 0x04, 0x02, 0x01,  // 234 - Стрелка 225 градусов
  0x07, 0x0F, 0x03, 0x05, 0x09, 0x10, 0x20, 0x40,  // 235 - Стрелка 315 градусов
  0x06, 0x7c, 0x12, 0x11, 0x12, 0x7c, 0x80, 0x00,  // Ą pl
  0x05, 0x20, 0x54, 0x54, 0x78, 0x80, 0x00, 0x00,  // ą pl
  0x05, 0x70, 0x88, 0x8a, 0x89, 0x50, 0x00, 0x00,  // Ć pl
  0x04, 0x30, 0x48, 0x4a, 0x49, 0x00, 0x00, 0x00,  // ć pl
  0x06, 0x08, 0x7f, 0x44, 0x40, 0x40, 0x40, 0x00,  // Ł pl
  0x03, 0x49, 0x7f, 0x44, 0x00, 0x00, 0x00, 0x00,  // ł pl
  0x05, 0xf8, 0x10, 0x22, 0x41, 0xf8, 0x00, 0x00,  // Ń pl
  0x05, 0x78, 0x10, 0x0a, 0x09, 0x70, 0x00, 0x00,  // ń pl
  0x05, 0x70, 0x88, 0x8a, 0x89, 0x70, 0x00, 0x00,  // Ó pl
  0x05, 0x30, 0x48, 0x4a, 0x49, 0x30, 0x00, 0x00,  // ó pl
  0x05, 0x7f, 0x49, 0x49, 0x49, 0x80, 0x00, 0x00,  // Ę pl
  0x05, 0x38, 0x54, 0x54, 0x54, 0x98, 0x00, 0x00,  // ę pl
  0x05, 0x90, 0xa8, 0xaa, 0xa9, 0x48, 0x00, 0x00,  // Ś pl
  0x05, 0x08, 0x54, 0x56, 0x55, 0x20, 0x00, 0x00,  // ś pl
  0x05, 0x88, 0xc8, 0xaa, 0x99, 0x88, 0x00, 0x00,  // Ź pl
  0x04, 0x48, 0x6a, 0x59, 0x48, 0x00, 0x00, 0x00,  // ź pl
  0x05, 0x44, 0x64, 0x55, 0x4c, 0x44, 0x00, 0x00,  // Ż pl
  0x04, 0x48, 0x6a, 0x58, 0x48, 0x00, 0x00, 0x00,  // ż pl
  0x04, 0x06, 0x09, 0x09, 0x06, 0x00, 0x00, 0x00,  // градус Цельсия
  0x05, 0xf8, 0x25, 0x22, 0x25, 0xf8, 0x00, 0x00,  // Ä Deutsch
  0x05, 0x20, 0x55, 0x54, 0x54, 0x79, 0x00, 0x00,  // ä Deutsch
  0x05, 0x78, 0x85, 0x84, 0x85, 0x78, 0x00, 0x00,  // Ö Deutsch
  0x05, 0x38, 0x45, 0x44, 0x45, 0x38, 0x00, 0x00,  // ö Deutsch
  0x05, 0x7c, 0x81, 0x80, 0x81, 0x7c, 0x00, 0x00,  // Ü Deutsch
  0x05, 0x3c, 0x41, 0x40, 0x21, 0x7c, 0x00, 0x00,  // ü Deutsch
  0x05, 0x85, 0xff, 0x49, 0x4e, 0x30, 0x00, 0x00,  // ß Deutsch
  0x05, 0x14, 0x14, 0xf7, 0x00, 0xff, 0x00, 0x00,  // Right T double all
  0x05, 0x00, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00,  // Right side double
  0x05, 0x14, 0x14, 0xf4, 0x04, 0xfc, 0x00, 0x00,  // Top Right double
  0x05, 0x14, 0x14, 0x17, 0x10, 0x1f, 0x00, 0x00,  // Bot Right double
  0x05, 0x10, 0x10, 0x1f, 0x10, 0x1f, 0x00, 0x00,  // Bot Right double V
  0x05, 0x14, 0x14, 0x14, 0x14, 0x1f, 0x00, 0x00,  // Bot Right double H
  0x05, 0x10, 0x10, 0x10, 0x10, 0xf0, 0x00, 0x00,  // Top Right
  0x05, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x00, 0x00,  // Bot Left
  0x05, 0x7e, 0x11, 0x11, 0x11, 0x7e, 0x00, 0x00,  // А
  0x05, 0x7f, 0x49, 0x49, 0x49, 0x31, 0x00, 0x00,  // Б
  0x05, 0x7f, 0x49, 0x49, 0x49, 0x36, 0x00, 0x00,  // B
  0x05, 0x7f, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00,  // Г
  0x06, 0xc0, 0x7e, 0x41, 0x41, 0x7e, 0xc0, 0x00,  // Д
  0x05, 0x7f, 0x49, 0x49, 0x49, 0x41, 0x00, 0x00,  // E
  0x05, 0x77, 0x08, 0x7f, 0x08, 0x77, 0x00, 0x00,  // Ж
  0x05, 0x41, 0x49, 0x49, 0x49, 0x36, 0x00, 0x00,  // З
  0x05, 0x7f, 0x10, 0x08, 0x04, 0x7f, 0x00, 0x00,  // И
  0x05, 0x7f, 0x10, 0x09, 0x04, 0x7f, 0x00, 0x00,  // Й
  0x05, 0x7f, 0x08, 0x14, 0x22, 0x41, 0x00, 0x00,  // K
  0x05, 0x40, 0x3e, 0x01, 0x01, 0x7f, 0x00, 0x00,  // Л
  0x05, 0x7f, 0x02, 0x0c, 0x02, 0x7f, 0x00, 0x00,  // M
  0x05, 0x7f, 0x08, 0x08, 0x08, 0x7f, 0x00, 0x00,  // H
  0x05, 0x3e, 0x41, 0x41, 0x41, 0x3e, 0x00, 0x00,  // O
  0x05, 0x7f, 0x01, 0x01, 0x01, 0x7f, 0x00, 0x00,  // П
  0x05, 0x7f, 0x09, 0x09, 0x09, 0x06, 0x00, 0x00,  // Р
  0x05, 0x3e, 0x41, 0x41, 0x41, 0x22, 0x00, 0x00,  // C
  0x05, 0x03, 0x01, 0x7f, 0x01, 0x03, 0x00, 0x00,  // T
  0x05, 0x27, 0x48, 0x48, 0x48, 0x3f, 0x00, 0x00,  // У
  0x07, 0x1c, 0x22, 0x22, 0x7f, 0x22, 0x22, 0x1c,  // Ф
  0x05, 0x63, 0x14, 0x08, 0x14, 0x63, 0x00, 0x00,  // X
  0x06, 0x7f, 0x40, 0x40, 0x40, 0x7f, 0xc0, 0x00,  // Ц
  0x05, 0x07, 0x08, 0x08, 0x08, 0x7f, 0x00, 0x00,  // Ч
  0x05, 0x7f, 0x40, 0x7e, 0x40, 0x7f, 0x00, 0x00,  // Ш
  0x06, 0x7f, 0x40, 0x7e, 0x40, 0x7f, 0xc0, 0x00,  // Щ
  0x07, 0x03, 0x01, 0x7f, 0x48, 0x48, 0x30, 0x00,  // Ъ
  0x07, 0x7f, 0x48, 0x48, 0x30, 0x00, 0x7F, 0x00,  // Ы
  0x05, 0x7f, 0x48, 0x48, 0x48, 0x30, 0x00, 0x00,  // Ь
  0x05, 0x22, 0x41, 0x49, 0x49, 0x3e, 0x00, 0x00,  // Э
  0x06, 0x7f, 0x08, 0x3e, 0x41, 0x41, 0x3e, 0x00,  // Ю
  0x05, 0x46, 0x29, 0x19, 0x09, 0x7f, 0x00, 0x00,  // Я
  0x05, 0x20, 0x54, 0x54, 0x54, 0x78, 0x00, 0x00,  // а
  0x05, 0x3c, 0x4a, 0x4a, 0x49, 0x31, 0x00, 0x00,  // б
  0x05, 0x7c, 0x54, 0x54, 0x54, 0x28, 0x00, 0x00,  // в
  0x04, 0x7c, 0x04, 0x04, 0x0c, 0x00, 0x00, 0x00,  // г
  0x06, 0xc0, 0x78, 0x44, 0x44, 0x78, 0xc0, 0x00,  // д
  0x05, 0x38, 0x54, 0x54, 0x54, 0x18, 0x00, 0x00,  // e
  0x05, 0x6c, 0x10, 0x7c, 0x10, 0x6c, 0x00, 0x00,  // ж
  0x05, 0x44, 0x54, 0x54, 0x54, 0x28, 0x00, 0x00,  // з
  0x05, 0x7c, 0x20, 0x10, 0x08, 0x7c, 0x00, 0x00,  // и
  0x05, 0x7c, 0x20, 0x12, 0x08, 0x7c, 0x00, 0x00,  // й
  0x05, 0x7c, 0x10, 0x10, 0x28, 0x44, 0x00, 0x00,  // к
  0x05, 0x40, 0x38, 0x04, 0x04, 0x7c, 0x00, 0x00,  // л
  0x05, 0x7c, 0x08, 0x10, 0x08, 0x7c, 0x00, 0x00,  // м
  0x05, 0x7c, 0x10, 0x10, 0x10, 0x7c, 0x00, 0x00,  // н
  0x05, 0x38, 0x44, 0x44, 0x44, 0x38, 0x00, 0x00,  // o
  0x05, 0x7c, 0x04, 0x04, 0x04, 0x7c, 0x00, 0x00,  // п
  0x05, 0xfc, 0x24, 0x24, 0x24, 0x18, 0x00, 0x00,  // р
  0x04, 0x38, 0x44, 0x44, 0x44, 0x00, 0x00, 0x00,  // с
  0x05, 0x0c, 0x04, 0x7c, 0x04, 0x0c, 0x00, 0x00,  // т
  0x05, 0x4c, 0x90, 0x90, 0x50, 0x3c, 0x00, 0x00,  // у
  0x07, 0x10, 0x28, 0x28, 0xfc, 0x28, 0x28, 0x10,  // ф
  0x05, 0x44, 0x28, 0x10, 0x28, 0x44, 0x00, 0x00,  // x
  0x05, 0x7c, 0x40, 0x40, 0x7c, 0xc0, 0x00, 0x00,  // ц
  0x05, 0x0c, 0x10, 0x10, 0x10, 0x7c, 0x00, 0x00,  // ч
  0x05, 0x7c, 0x40, 0x78, 0x40, 0x7c, 0x00, 0x00,  // ш
  0x06, 0x7c, 0x40, 0x78, 0x40, 0x7c, 0xc0, 0x00,  // щ
  0x06, 0x04, 0x7c, 0x50, 0x50, 0x50, 0x20, 0x00,  // ъ
  0x05, 0x7c, 0x50, 0x50, 0x20, 0x7c, 0x00, 0x00,  // ы
  0x05, 0x7c, 0x50, 0x50, 0x50, 0x20, 0x00, 0x00,  // ь
  0x05, 0x28, 0x44, 0x54, 0x54, 0x38, 0x00, 0x00,  // э
  0x06, 0x7c, 0x10, 0x38, 0x44, 0x44, 0x38, 0x00,  // ю
  0x05, 0x48, 0x34, 0x14, 0x14, 0x7c, 0x00, 0x00   // я
};
//==========================================
const uint8_t znaki5x7[] PROGMEM = { 6,
0x02, 0x03,0x03,0x00,0x00,0x00,     //градус
0x05, 0x3E,0x41,0x41,0x63,0x22,     //C
0x01, 0x60,0x00,0x00,0x00,0x00,     //.
0x03, 0x72,0x57,0x22,0x00,0x00,     //+D
0x03, 0x72,0x52,0x22,0x00,0x00,     //-D
0x03, 0x32,0x47,0x72,0x00,0x00,     //+U
0x03, 0x32,0x42,0x72,0x00,0x00,     //-U
0x05, 0x38,0x44,0x43,0x44,0x38,     //кропля
0x05, 0x43,0x33,0x08,0x66,0x61,     //відсотки
0x05, 0x44,0x48,0x5F,0x48,0x44,     //тиск
0x04, 0x7F,0x08,0x08,0x7F,0x00,     //H
0x03, 0x4C,0x52,0x3C,0x00,0x00,     //g
0x05, 0x10,0x5E,0x3F,0x1E,0x10,     //колокол л
0x05, 0x10,0x1E,0x3F,0x5E,0x10      //колокол п
};
//==========================================
const uint8_t znaki5x8[] PROGMEM = { 6,
0x02, 0x03,0x03,0x00,0x00,0x00,     //градус
0x05, 0x7E,0x81,0x81,0xc3,0x42,     //C
0x01, 0xC0,0x00,0x00,0x00,0x00,     //.
0x03, 0xF2,0x97,0x62,0x00,0x00,     //+D
0x03, 0xF2,0x92,0x62,0x00,0x00,     //-D
0x03, 0xB2,0xA7,0x72,0x00,0x00,     //+U
0x03, 0xB2,0xA2,0x72,0x00,0x00,     //-U
0x05, 0x70,0x8C,0x83,0x8C,0x70,     //кропля
0x05, 0x83,0x63,0x18,0xC6,0xC1,     //відсотки
0x05, 0x88,0x90,0xbf,0x90,0x88,     //тиск
0x04, 0xff,0x08,0x08,0xff,0x00,     //H
0x03, 0x98,0xa4,0x78,0x00,0x00,     //g
0x05, 0x20,0xBC,0x7E,0x3C,0x20,     //колокол л
0x05, 0x20,0x3C,0x7E,0xBC,0x20,     //колокол п
0x02, 0xC0,0xC0,0x00,0x00,0x00,     //. жирная
};
//==========================================
const uint8_t dig4x7[] PROGMEM = { 5,
0x04, 0x3E,0x41,0x41,0x3E,     //0
0x04, 0x00,0x42,0x7F,0x40,     //1
0x04, 0x72,0x49,0x49,0x46,     //2
0x04, 0x22,0x49,0x49,0x36,     //3
0x04, 0x0C,0x0A,0x09,0x7F,     //4
0x04, 0x27,0x49,0x49,0x31,     //5
0x04, 0x3E,0x49,0x49,0x32,     //6
0x04, 0x01,0x71,0x09,0x07,     //7
0x04, 0x36,0x49,0x49,0x36,     //8
0x04, 0x26,0x49,0x49,0x3E      //9
};
//==========================================
const uint8_t dig4x8[] PROGMEM = { 5,
0x04, 0x7E,0x81,0x81,0x7E,     //0
0x04, 0x00,0x82,0xFF,0x80,     //1
0x04, 0xC2,0xA1,0x91,0x8E,     //2
0x04, 0x42,0x89,0x89,0x76,     //3
0x04, 0x1C,0x12,0x11,0xFF,     //4
0x04, 0x4F,0x89,0x89,0x71,     //5
0x04, 0x7E,0x89,0x89,0x71,     //6
0x04, 0x01,0xF1,0x09,0x07,     //7
0x04, 0x76,0x89,0x89,0x76,     //8
0x04, 0x46,0x89,0x89,0x7E      //9
};
//==========================================
const uint8_t dig4x7dig[] PROGMEM = { 5,
0x04, 0x7F,0x41,0x41,0x7F,     //0
0x04, 0x00,0x00,0x7F,0x00,     //1
0x04, 0x79,0x49,0x49,0x4F,     //2
0x04, 0x49,0x49,0x49,0x7F,     //3
0x04, 0x0F,0x08,0x08,0x7F,     //4
0x04, 0x4F,0x49,0x49,0x79,     //5
0x04, 0x7F,0x49,0x49,0x79,     //6
0x04, 0x01,0x01,0x01,0x7F,     //7
0x04, 0x7F,0x49,0x49,0x7F,     //8
0x04, 0x4F,0x49,0x49,0x7F      //9
};
//==========================================
const uint8_t dig4x8dig[] PROGMEM = { 5,
0x04, 0xFF,0x81,0x81,0xFF,     //0
0x04, 0x00,0x00,0xFF,0x00,     //1
0x04, 0xF9,0x89,0x89,0x8F,     //2
0x04, 0x81,0x89,0x89,0xFF,     //3
0x04, 0x0F,0x08,0x08,0xFF,     //4
0x04, 0x8F,0x89,0x89,0xF9,     //5
0x04, 0xFF,0x89,0x89,0xF9,     //6
0x04, 0x01,0x01,0x01,0xFF,     //7
0x04, 0xFF,0x89,0x89,0xFF,     //8
0x04, 0x8F,0x89,0x89,0xFF      //9
};
//==========================================
const uint8_t dig5x7[] PROGMEM = { 6,
0x05, 0x3E,0x41,0x41,0x41,0x3E,     //0
0x05, 0x00,0x42,0x7F,0x40,0x00,     //1
0x05, 0x62,0x51,0x49,0x49,0x66,     //2
0x05, 0x22,0x49,0x49,0x49,0x36,     //3
0x05, 0x18,0x14,0x12,0x79,0x10,     //4
0x05, 0x27,0x49,0x49,0x49,0x31,     //5
0x05, 0x3E,0x49,0x49,0x49,0x32,     //6
0x05, 0x01,0x01,0x71,0x0D,0x03,     //7
0x05, 0x36,0x49,0x49,0x49,0x36,     //8
0x05, 0x26,0x49,0x49,0x49,0x3E      //9
};
//==========================================
const uint8_t dig5x8[] PROGMEM = { 6,
0x05, 0x7E,0x81,0x81,0x81,0x7E,     //0
0x05, 0x00,0x82,0xFF,0x80,0x00,     //1
0x05, 0xE2,0x91,0x91,0x89,0xC6,     //2
0x05, 0x42,0x89,0x89,0x89,0x76,     //3
0x05, 0x38,0x24,0x22,0xF1,0x20,     //4
0x05, 0x47,0x89,0x89,0x89,0x71,     //5
0x05, 0x7E,0x89,0x89,0x89,0x72,     //6
0x05, 0x01,0x01,0xF1,0x09,0x07,     //7
0x05, 0x76,0x89,0x89,0x89,0x76,     //8
0x05, 0x46,0x89,0x89,0x89,0x7E      //9
};
//==========================================
const uint8_t dig5x7dig[] PROGMEM = { 6,
0x05, 0x7F,0x41,0x41,0x41,0x7F,     //0
0x05, 0x00,0x00,0x00,0x7F,0x00,     //1
0x05, 0x79,0x49,0x49,0x49,0x4F,     //2
0x05, 0x49,0x49,0x49,0x49,0x7F,     //3
0x05, 0x0F,0x08,0x08,0x08,0x7F,     //4
0x05, 0x4F,0x49,0x49,0x49,0x79,     //5
0x05, 0x7F,0x49,0x49,0x49,0x79,     //6
0x05, 0x01,0x01,0x01,0x01,0x7F,     //7
0x05, 0x7F,0x49,0x49,0x49,0x7F,     //8
0x05, 0x4F,0x49,0x49,0x49,0x7F      //9
};
//==========================================
const uint8_t dig5x8dig[] PROGMEM = { 6,
0x05, 0xFF,0x81,0x81,0x81,0xFF,     //0
0x05, 0x00,0x00,0x00,0xFF,0x00,     //1
0x05, 0xF9,0x89,0x89,0x89,0x8F,     //2
0x05, 0x89,0x89,0x89,0x89,0xFF,     //3
0x05, 0x0F,0x08,0x08,0x08,0xFF,     //4
0x05, 0x8F,0x89,0x89,0x89,0xF9,     //5
0x05, 0xFF,0x89,0x89,0x89,0xF9,     //6
0x05, 0x01,0x01,0x01,0x01,0xFF,     //7
0x05, 0xFF,0x89,0x89,0x89,0xFF,     //8
0x05, 0x8F,0x89,0x89,0x89,0xFF      //9
};
//==========================================
const uint8_t dig5x7rn[] PROGMEM = { 6,
0x05, 0x3E, 0x41, 0x41, 0x7F, 0x3E,     //0
0x05, 0x04, 0x02, 0x7F, 0x7F, 0x00,     //1
0x05, 0x71, 0x49, 0x49, 0x4F, 0x46,     //2
0x05, 0x41, 0x49, 0x49, 0x7F, 0x36,     //3
0x05, 0x0F, 0x08, 0x08, 0x7E, 0x7E,     //4
0x05, 0x4F, 0x49, 0x49, 0x79, 0x31,     //5
0x05, 0x3E, 0x49, 0x49, 0x79, 0x30,     //6
0x05, 0x01, 0x71, 0x79, 0x0F, 0x07,     //7
0x05, 0x36, 0x49, 0x49, 0x7F, 0x36,     //8
0x05, 0x06, 0x49, 0x49, 0x7F, 0x3E      //9
};
//===========================================
const uint8_t dig5x8rn[] PROGMEM = { 6,
0x05, 0x7E, 0x81, 0x81, 0xFF, 0x7E,     //0
0x05, 0x04, 0x02, 0xFF, 0xFF, 0x00,     //1
0x05, 0xF1, 0x89, 0x89, 0x8F, 0x86,     //2
0x05, 0x81, 0x89, 0x89, 0xFF, 0x76,     //3
0x05, 0x1F, 0x10, 0x10, 0xFE, 0xFE,     //4
0x05, 0x8F, 0x89, 0x89, 0xF9, 0x71,     //5
0x05, 0x7E, 0x89, 0x89, 0xF9, 0x70,     //6
0x05, 0x01, 0xC1, 0xF1, 0x3F, 0x0F,     //7
0x05, 0x76, 0x89, 0x89, 0xFF, 0x76,     //8
0x05, 0x0E, 0x91, 0x91, 0xFF, 0x7E      //9
};
//==========================================
const uint8_t dig5x7rndig[] PROGMEM = { 6,
0x05, 0x7F,0x41,0x41,0x7F,0x7F,     //0
0x05, 0x00,0x00,0x7F,0x7F,0x00,     //1
0x05, 0x79,0x49,0x49,0x4F,0x4F,     //2
0x05, 0x49,0x49,0x49,0x7F,0x7F,     //3
0x05, 0x0F,0x08,0x08,0x7F,0x7F,     //4
0x05, 0x4F,0x49,0x49,0x79,0x79,     //5
0x05, 0x7F,0x49,0x49,0x79,0x79,     //6
0x05, 0x01,0x01,0x01,0x7F,0x7F,     //7
0x05, 0x7F,0x49,0x49,0x7F,0x7F,     //8
0x05, 0x4F,0x49,0x49,0x7F,0x7F      //9
};
//==========================================
const uint8_t dig5x8rndig[] PROGMEM = { 6,
0x05, 0xFF,0x81,0x81,0xFF,0xFF,     //0
0x05, 0x00,0x00,0xFF,0xFF,0x00,     //1
0x05, 0xF9,0x89,0x89,0x8F,0x8F,     //2
0x05, 0x89,0x89,0x89,0xFF,0xFF,     //3
0x05, 0x0F,0x08,0x08,0xFF,0xFF,     //4
0x05, 0x8F,0x89,0x89,0xF9,0xF9,     //5
0x05, 0xFF,0x89,0x89,0xF9,0xF9,     //6
0x05, 0x01,0x01,0x01,0xFF,0xFF,     //7
0x05, 0xFF,0x89,0x89,0xFF,0xFF,     //8
0x05, 0x8F,0x89,0x89,0xFF,0xFF      //9
};
//==========================================
const uint8_t dig6x7[] PROGMEM = { 7,
0x06, 0x3E, 0x7F, 0x41, 0x41, 0x7F, 0x3E,
0x06, 0x00, 0x42, 0x7F, 0x7F, 0x40, 0x00,
0x06, 0x42, 0x63, 0x71, 0x59, 0x4F, 0x46,
0x06, 0x22, 0x63, 0x41, 0x49, 0x7F, 0x36,
0x06, 0x18, 0x1C, 0x16, 0x13, 0x7F, 0x7F,
0x06, 0x27, 0x67, 0x45, 0x45, 0x7D, 0x39,
0x06, 0x3E, 0x7F, 0x49, 0x49, 0x7B, 0x32,
0x06, 0x01, 0x01, 0x71, 0x79, 0x0F, 0x07,
0x06, 0x36, 0x7F, 0x49, 0x49, 0x7F, 0x36,
0x06, 0x26, 0x6F, 0x49, 0x49, 0x7F, 0x3E
};
//==========================================
const uint8_t dig6x8[] PROGMEM = { 7,
0x06, 0x7E,0xFF,0x81,0x81,0xFF,0x7E,     //0
0x06, 0x00,0x82,0xFF,0xFF,0x80,0x00,     //1
0x06, 0xC2,0xE3,0xB1,0x99,0x8F,0x86,     //2
0x06, 0x42,0xC3,0x89,0x89,0xFF,0x76,     //3
0x06, 0x38,0x3C,0x26,0x23,0xFF,0xFF,     //4
0x06, 0x4F,0xCF,0x89,0x89,0xF9,0x71,     //5
0x06, 0x7E,0xFF,0x89,0x89,0xFB,0x72,     //6
0x06, 0x01,0x01,0xF1,0xF9,0x0F,0x07,     //7
0x06, 0x76,0xFF,0x89,0x89,0xFF,0x76,     //8
0x06, 0x4E,0xDF,0x91,0x91,0xFF,0x7E      //9
};
//==========================================
const uint8_t dig6x7dig[] PROGMEM = { 7,
0x06, 0x7F,0x7F,0x41,0x41,0x7F,0x7F,     //0
0x06, 0x00,0x00,0x7F,0x7F,0x00,0x00,     //1
0x06, 0x79,0x79,0x49,0x49,0x4F,0x4F,     //2
0x06, 0x49,0x49,0x49,0x49,0x7F,0x7F,     //3
0x06, 0x0F,0x0F,0x08,0x08,0x7F,0x7F,     //4
0x06, 0x4F,0x4F,0x49,0x49,0x79,0x79,     //5
0x06, 0x7F,0x7F,0x49,0x49,0x79,0x79,     //6
0x06, 0x01,0x01,0x01,0x01,0x7F,0x7F,     //7
0x06, 0x7F,0x7F,0x49,0x49,0x7F,0x7F,     //8
0x06, 0x4F,0x4F,0x49,0x49,0x7F,0x7F      //9
};
//==========================================
const uint8_t dig6x8dig[] PROGMEM = { 7,
0x06, 0xFF,0xFF,0x81,0x81,0xFF,0xFF,     //0
0x06, 0x00,0x00,0xFF,0xFF,0x00,0x00,     //1
0x06, 0xF9,0xF9,0x89,0x89,0x8F,0x8F,     //2
0x06, 0x89,0x89,0x89,0x89,0xFF,0xFF,     //3
0x06, 0x0F,0x0F,0x08,0x08,0xFF,0xFF,     //4
0x06, 0x8F,0x8F,0x89,0x89,0xF9,0xF9,     //5
0x06, 0xFF,0xFF,0x89,0x89,0xF9,0xF9,     //6
0x06, 0x01,0x01,0x01,0x01,0xFF,0xFF,     //7
0x06, 0xFF,0xFF,0x89,0x89,0xFF,0xFF,     //8
0x06, 0x8F,0x8F,0x89,0x89,0xFF,0xFF      //9
};
//==========================================
const uint8_t dig6x8bigH[] PROGMEM = { 7,
0x06, 0xF8,0xFC,0x0C,0x0C,0xFC,0xF8,     //0
0x06, 0x00,0x18,0xFC,0xFC,0x00,0x00,     //1
0x06, 0x18,0x1C,0x0C,0xCC,0xFC,0x38,     //2
0x06, 0x18,0x1C,0xCC,0xCC,0xFC,0xB8,     //3
0x06, 0xC0,0xF0,0x3C,0x0C,0xFC,0xFC,     //4
0x06, 0xFC,0xFC,0xCC,0xCC,0xCC,0x8C,     //5
0x06, 0xF8,0xFC,0xCC,0xCC,0xDC,0x98,     //6
0x06, 0x0C,0x0C,0x0C,0xCC,0xFC,0x3C,     //7
0x06, 0xB8,0xFC,0xCC,0xCC,0xFC,0xB8,     //8
0x06, 0xF8,0xFC,0x0C,0x0C,0xFC,0xF8      //9
};
//==========================================
const uint8_t dig6x8bigL[] PROGMEM = { 7,
0x06, 0x1F,0x3F,0x30,0x30,0x3F,0x1F,     //0
0x06, 0x00,0x30,0x3F,0x3F,0x30,0x00,     //1
0x06, 0x30,0x3C,0x3F,0x33,0x30,0x30,     //2
0x06, 0x18,0x38,0x30,0x30,0x3F,0x1F,     //3
0x06, 0x03,0x03,0x03,0x03,0x3F,0x3F,     //4
0x06, 0x18,0x38,0x30,0x30,0x3F,0x1F,     //5
0x06, 0x1F,0x3F,0x30,0x30,0x3F,0x1F,     //6
0x06, 0x00,0x00,0x3F,0x3F,0x00,0x00,     //7
0x06, 0x1F,0x3F,0x30,0x30,0x3F,0x1F,     //8
0x06, 0x19,0x3B,0x33,0x33,0x3F,0x1F      //9
};
