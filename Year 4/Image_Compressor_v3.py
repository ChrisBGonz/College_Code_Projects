#!/usr/bin/env python
# coding: utf-8

# In[2]:


from PIL import Image
import os

def compress_image(input_path, output_path, quality):
    """Compress an image by reducing its quality."""
    
    try:
        img = Image.open(input_path)
        img.save(output_path, "JPEG", quality=quality, optimize=True)
        print(f"Saved {output_path} (quality={quality})")
        
    except Exception as e:
        print(f"Error processing {input_path}: {e}")

###########################################################################

if __name__ == "__main__":
    
    base_input_dir = "/Users/christophergonzalez/Desktop/Test_Photos"
    output_dirs = {
        20: "/Users/christophergonzalez/Desktop/C1",
        10: "/Users/christophergonzalez/Desktop/C2",
        1:  "/Users/christophergonzalez/Desktop/C3"
    }

    total_images = 200  # Number of images to process

    for i in range(1, total_images + 1):
        input_file = os.path.join(base_input_dir, f"{i}.jpg")

        # Compress for each quality level
        for quality, out_dir in output_dirs.items():
            output_file = os.path.join(out_dir, f"C{list(output_dirs.keys()).index(quality)+1}-{i}.jpg")
            compress_image(input_file, output_file, quality)


# In[ ]:




