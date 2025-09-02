
:: Для получения пользовательского
:: FOR /F "tokens=*" %%A IN ('TYPE CON') DO SET INPUT=%%A
:: ECHO Вы ввели: "%INPUT%"
pause
D:
cd D:\Denis\outfront
git init
pause
git add .
pause
git commit -m "new user commit"
pause
git status
pause


