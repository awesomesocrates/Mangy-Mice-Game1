#ifndef GLOBALS_H
#define GLOBALS_H


//Screen dimension constants
const int SCREEN_WIDTH = 426;
const int SCREEN_HEIGHT = 240;
//const int SCREEN_FPS = 60;
//const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

//int SCREEN_WIDTH_TRUE;
//int SCREEN_HEIGHT_TRUE;

//The dimensions of the level
const int LEVEL_WIDTH = 512;
const int LEVEL_HEIGHT = 512;

//Tile constants
const int TILE_WIDTH = 32;
const int TILE_HEIGHT = 32;
const int TOTAL_TILES = 256;
const int TOTAL_TILE_SPRITES = 16;

//The different tile sprites
/*
const int TILE_RED = 0;
const int TILE_GREEN = 1;
const int TILE_BLUE = 2;
const int TILE_CENTER = 3;
const int TILE_TOP = 4;
const int TILE_TOPRIGHT = 5;
const int TILE_RIGHT = 6;
const int TILE_BOTTOMRIGHT = 7;
const int TILE_BOTTOM = 8;
const int TILE_BOTTOMLEFT = 9;
const int TILE_LEFT = 10;
const int TILE_TOPLEFT = 11;
*/

#ifdef _SDL_TTF_H
extern TTF_Font *gFont;// = NULL;
#endif



//Starts up SDL and creates window
bool init();

int getTotalTiles();

//The window we'll be rendering to
extern SDL_Window* gWindow;// = NULL;

//The window renderer
extern SDL_Renderer* gRenderer;// = NULL;

class LevelInfo
{
	public:
		LevelInfo();
		int h;
		int w;

};

class ScreenInfo
{
	public:
		ScreenInfo();
		int w;
		int h;
};

//The tile
class Tile
{
    public:
		//Initializes position and type
		Tile( int x, int y, int tileType );

		int getTotal();

		//Shows the tile
		void render( SDL_Rect& camera );

		//Get the tile type
		int getType();

		//Get the collision box
		SDL_Rect getBox();

    private:
		//The attributes of the tile
		SDL_Rect mBox;

		//The tile type
		int mType;
		int tileTotal;
};

//Loads media
bool loadMedia( Tile* tiles[] , SDL_Renderer* );

//Frees media and shuts down SDL
void close( Tile* tiles[] );

//Box collision detector
bool checkCollision( SDL_Rect a, SDL_Rect b );

//Checks collision box against set of tiles and floor
bool touchesWall( SDL_Rect box, Tile* tiles[] );
bool touchesFloor( SDL_Rect box, Tile* tiles[] );

Tile* getCollide(SDL_Rect,Tile**);

//Sets tiles from tile map
bool setTiles( Tile *tiles[] );



//Texture wrapper class
class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path , SDL_Renderer* );

		#ifdef _SDL_TTF_H
		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor, SDL_Renderer*  );
		#endif

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};


//Scene textures
extern LTexture gDotTexture;
extern LTexture gTileTexture;
extern SDL_Rect gTileClips[ TOTAL_TILE_SPRITES ];


#endif
