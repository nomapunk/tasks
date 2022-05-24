rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\generator.exe 3 15 50 100" "tests\02" 2
call scripts\gen-input-via-stdout.bat "files\generator.exe 7 1000 10000 100000 100000 100000 100000 100000" "tests\03" 3
call scripts\gen-answer.bat tests\01 tests\01.a "tests" ""
call scripts\gen-answer.bat tests\02 tests\02.a "tests" ""
call scripts\gen-answer.bat tests\03 tests\03.a "tests" ""

