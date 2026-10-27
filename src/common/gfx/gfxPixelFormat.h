#pragma once

#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_platform.h>

/// Pixel format of the screen surface and the streaming texture it's uploaded to.
/// All loaded sprites are converted to the screen surface's format too, so this
/// decides the memory use of nearly all graphics.
///
/// On the Wii/GameCube (libogc) 32-bit textures don't fit into memory. There the
/// 16-bit ARGB1555 format is used instead; it maps cleanly to the GX texture
/// format RGB5A3, and the game only needs 1-bit transparency.
#if defined(SDL_PLATFORM_OGC)
constexpr SDL_PixelFormat GFX_PIXEL_FORMAT = SDL_PIXELFORMAT_ARGB1555;
#else
constexpr SDL_PixelFormat GFX_PIXEL_FORMAT = SDL_PIXELFORMAT_ARGB8888;
#endif
