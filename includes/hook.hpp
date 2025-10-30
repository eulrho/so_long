#ifndef HOOK_H
# define HOOK_H

int key_hook(int keycode, void *param);
int render_next_frame(void *param);
int x_close(int keycode, void *param);

#endif
