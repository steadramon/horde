<?php
/* This file is automatically generated.  DO NOT EDIT!
   Instead, edit gen-stringprep-tables.pl and re-run.  */

namespace Znerol\Component\Stringprep\RFC3454;
class C_5 {
  public static function filter($cp) {
    if ($cp >= 0x00D800 && $cp <= 0x00DFFF) return false;
    return true;
  }
}

