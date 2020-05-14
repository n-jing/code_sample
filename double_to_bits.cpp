void double_to_bits(double val)
{
  unsigned idx;
  unsigned char arr[sizeof val];

  memcpy (arr, &val, sizeof val);

  for (idx=CHAR_BIT * sizeof val; idx-- ; ) {
    putc(
      ( arr[idx/CHAR_BIT] & (1u << (idx%CHAR_BIT) ) )
      ? '1'
      : '0'
      , stdout
      );
  }
  putc('\n', stdout);
}
