#pragma once
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#include "app/memory/hook.h"

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx11.h"
#include "scripthook/inc/natives.h"

#include "game/rageControl/control.h"
#include "uiBase/uiBaseWindow.h"
#include "gameClock/CClock.h"
#include "scripthookTh.h"

#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")


extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


class mRender
{
	static int  open_window_btn;
	static bool init;
	static bool show_window;
	static bool mInitialized;
	static bool ImGuiCursorUsage;
	
	static HWND	window;
	static ID3D11Device* p_device;
	static ID3D11DeviceContext* p_context;
	static IDXGISwapChain* p_SwapChain;

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static void CreateDevice();
	static void InitBackend();
	static void PresentImage();
	static void RenderLoop();
		
	static void n_ClipCursor(LPRECT rect);
	static int	n_ShowCursor(bool visible);
	static void SetMouseCursorState(bool state, HWND hwnd);

	static void LoadWindowsFont();
	static void mStyle();

public:

	static void SetCursorImguiUsage(bool state);
	static void SetOpenWindowBtn(int btn);
	static void Init();
	static void Shutdown();
};
