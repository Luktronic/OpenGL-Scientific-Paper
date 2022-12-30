import numpy as np
import matplotlib.pyplot as plt


def generate_0():
    n = 4
    opengl= (15389, 6624, 9172, 6887)
    vulkan = (21587, 15915, 10736, 7741)
    directx =(20341, 16571, 10015, 6958)

    fig, ax = plt.subplots(figsize=(12,10))
    index = np.arange(n)
    bar_width = 0.25
    opacity = 0.9
    ax.bar(index, opengl, bar_width, alpha=opacity, color='#0277bd',
                    label='OpenGL')
    ax.bar(index+bar_width, directx, bar_width, alpha=opacity, color='#1ca813', label='DirectX')
    ax.bar(index+bar_width*2, vulkan, bar_width, alpha=opacity, color='#8d181b',
                    label='Vulkan')
    ax.set_xlabel('GPU', fontsize=20)
    ax.set_ylabel('Points', fontsize=20)
    ax.set_yticklabels(("0", "5000", "10000", "15000", "20000"), fontsize=15)
    ax.set_title('Graphics API comparison', fontsize=25)
    ax.set_xticks(index + bar_width)
    ax.set_xticklabels(('GeForce RTX 3090','Radeon RX 6800 XT','GeForce GTX 1080 Ti','GeForce RTX 2060'
        ), fontsize=15)
    ax.legend(fontsize=20)

    

    plt.savefig(f"writing/images/generated_comparison.png", dpi=300, bbox_inches='tight', pad_inches=0)