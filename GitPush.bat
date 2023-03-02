call git status
call git add .
set /P input=Input commit text: 
call git commit -m"%input%"
call git push 
pause