#ifndef MUSIC_HPP
# define MUSIC_HPP

extern "C" {
	# include "../bass24-osx/c/bass.h"
}

# include <stdexcept>

using namespace std;

// bgm path
# define BACKGROUND "/Users/rho-eul/study/so_long/bgm/game_bgm.mp3"
# define WALK "/Users/rho-eul/study/so_long/bgm/walk.mp3"
# define MOUSE "/Users/rho-eul/study/so_long/bgm/mouse.mp3"
# define EXIT "/Users/rho-eul/study/so_long/bgm/exit.mp3"
# define ATTACK "/Users/rho-eul/study/so_long/bgm/fire.mp3"

class Music {
	private:
		HSTREAM 	backgroundHandle;
		HSTREAM 	walkHandle;
		HSTREAM 	collectionHandle;
		HSTREAM 	exitHandle;
		HSTREAM		attackHandle;

		void		play(HSTREAM);
		const char*	getErrorMessage(int) const;
	public:
		Music();
		~Music();
		void		init();
		void		stop();
		void		playBackgroundSound();
		void		playWalkSound();
		void		playCollectionSound();
		void		playExitSound();
		void		playAttackSound();

		class BassException : public exception {
		private:
			const char* message;
		public:
			BassException(const char* message) : message(message) {};
			const char* what() const throw();
		};
};

#endif
