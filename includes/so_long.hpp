#ifndef SO_LONG_H
# define SO_LONG_H

# include <iostream>
# include <fstream>
# include <string>
# include <vector>
#include "../includes/Game.hpp"

using namespace std;

// check_valid
void	is_valid_file(ifstream &file, string file_name);
void	is_valid_map(Map &map);
void	is_valid_path(Map &map);
void	print_error(int error_no);

// hook
int key_hook(int keycode, void *param);
int render_next_frame(void *param);
int x_close(int keycode, void *param);

#endif
