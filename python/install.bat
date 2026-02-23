@echo off
echo "正在激活 Conda 环境..."
call conda activate picturework

echo "正在使用 PyInstaller 打包 changeBackground.py..."
pyinstaller --onefile --windowed changeBackground.py

echo "打包完成！"
pause