
#define OBJECT_ATTR0_Y_MASK 0x0FF
#define OBJECT_ATTR1_X_MASK 0x1FF

typedef struct obj_attrs {
	uint16 attr0;
	uint16 attr1;
	uint16 attr2;
	uint16 pad;
} __attribute__((packed, aligned(4))) obj_attrs;
typedef uint32    tile_4bpp[8];
typedef tile_4bpp tile_block[512];

#define oam_mem            ((volatile obj_attrs *)MEM_OAM)
#define tile_mem           ((volatile tile_block *)MEM_VRAM)
#define object_palette_mem ((volatile rgb15 *)(MEM_PAL + 0x200))
//#define bg0_palette_mem		((volatile rgb15 *)(MEM_PAL + 0x200))

// Set the position of an object to specified x and y coordinates
static inline void set_object_position(volatile obj_attrs *object, int x,
                                       int y)
{
	object->attr0 = (object->attr0 & ~OBJECT_ATTR0_Y_MASK) |
	                (y & OBJECT_ATTR0_Y_MASK);
	object->attr1 = (object->attr1 & ~OBJECT_ATTR1_X_MASK) |
	                (x & OBJECT_ATTR1_X_MASK);
}
