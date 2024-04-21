from math import atan
stick_len, tile_side = float(input()), float(input())
print(((stick_len**2 / tile_side**2) / (atan(1) * 4)))