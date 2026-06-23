#include "cub3d.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    mlx_context mlx = mlx_init();
    mlx_window_create_info info = { 0 };
    info.title = "Hello World!";
    info.width = 400;
    info.height = 400;
    mlx_window win = mlx_new_window(mlx, &info);
    (void)win;
    mlx_loop(mlx);
}