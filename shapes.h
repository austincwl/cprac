typedef struct {
    double radius;
} circle_t;

typedef struct {
    double width;
} square_t;

typedef struct {
    double width;
    double length;
} rectangle_t;

typedef union {
    circle_t circle; //type = 'c'
    square_t square; //type = 's'
    rectangle_t rectangle; //type = 'r'
} shape_t;

typedef struct {
    char type;
    shape_t shape;
} figure_t;

extern void create_shape(figure_t *figure);
extern void print_shape(figure_t *figure);