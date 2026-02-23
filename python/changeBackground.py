from PIL import Image, ImageOps
import sys
import json

def ChangeBackgroudColor():
    # 读取输入路径、输出路径
    input_path = sys.argv[1]
    output_path = sys.argv[2]
    # 从json中读取颜色范围
    ColorRange_json = sys.argv[3]
    ColorRange = json.loads(ColorRange_json)
    ColorRange_r = ColorRange[0]
    ColorRange_g = ColorRange[1]
    ColorRange_b = ColorRange[2]
    try:
        size = len(ColorRange_r) // 2  # 每种颜色范围的数量
        if size * 2 != len(ColorRange_r) or size * 2 != len(ColorRange_g) or size * 2 != len(ColorRange_b):
            raise ValueError("ColorRange arrays must have even lengths.")
    except Exception as e:
        print(f"Error parsing ColorRange: {e}")
        return -1
    # 从json中读取目标颜色
    targetColor_json = sys.argv[4]
    targetColor = json.loads(targetColor_json)

    print("Input Path:", input_path)
    print("Output Path:", output_path)
    print("Color Range:", ColorRange)
    print("Target Color:", targetColor)
    print("size:",size)

    # 打开图片，并根据EXIF信息校正方向
    img = Image.open(input_path).convert("RGB")
    img = ImageOps.exif_transpose(img)  # 自动旋转到正确方向

    # 获取像素
    pixels = img.load()
    width, height = img.size
    for x in range(width):
        for y in range(height):
            r, g, b = pixels[x, y]
            
            # 判断是否在给定范围
            for i in range(1, size+1):
                if (r >= ColorRange_r[2*i-2] and r <= ColorRange_r[2*i-1]
                    and g >= ColorRange_g[2*i-2] and g <= ColorRange_g[2*i-1]
                    and b >= ColorRange_b[2*i-2] and b <= ColorRange_b[2*i-1]):
                        pixels[x, y] = (targetColor["r"], targetColor["g"], targetColor["b"])  # 替换为目标颜色
                        break # 找到匹配后跳出循环
    # 保存图片
    try:
        img.save(output_path, format="JPEG", optimize=True)
        print("Image saved successfully.")
        return 0
    except Exception as e:
        print(f"Error saving image: {e}")
        return -1
    
if __name__ == "__main__":
    ChangeBackgroudColor()
    