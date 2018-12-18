<?php
while (true) {
    fwrite (STDOUT, ">> ");
    echo str_replace (["?", "？", "吗"], ["!", "！", ""], fgets(STDIN));
}

