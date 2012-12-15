EXEC=./test_dynamic_fsa

echo "Tests avec le mot \"mechant\""
echo "[Test1] je suis vraiment mechant"
$EXEC "mechant" "je suis vraiment mechant"

echo "[Test2] je suis vraiment mechant et je le resterais"
$EXEC "mechant" "je suis vraiment mechant et je le resterais"

echo "Tests avec le mot \"gentil\""
echo "[Test3] je suis vraiment gentil, le plus gentil du monde"
$EXEC "gentil" "je suis vraiment gentil, le plus gentil du monde"

echo "[Test4] GenTil gENtIL gentil GentiL"
$EXEC "gentil" "GenTil gENtIL gentil GentiL"

echo "[Test5] alphabet vide"
$EXEC "" "lol"

echo "[Test6] chaine a tokenize vide"
$EXEC "lol" ""
