# ft_printf

'.'
For integer specifiers (d, i, o, u, x, X) − precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For s − this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. For c type − it has no effect. When no precision is specified, the default is 1. If the period is specified without an explicit value for precision, 0 is assumed.

'#'
Used with o, x or X specifiers the value is preceded with 0, 0x or 0X respectively for values different than zero.

'+'
prints positive numbers and zero with '+', only signed formats, overwrites the ' ' flag

' '
prints positive numbers and zero with ' ', only signed formats

'min_width'
simple number, specifies minimal width of the output, longer outputs possible. leading '0' counts as flag

'-'
Left-justify within the given field width; Right justification is the default, overwrites '0'

'0'
Left-pads the number with zeroes (0) instead of spaces, where padding is specified
