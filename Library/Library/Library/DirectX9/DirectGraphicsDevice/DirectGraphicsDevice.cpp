//--------------------------------------------------
//	include
//--------------------------------------------------
#include"DirectGraphicsDevice.h"
#include"..\Library\Library\MyDefine\macro.h"

namespace Lib
{
	namespace Dx9
	{
		//--------------------------------------------------
		//	コンストラクタ : デストラクタ
		//--------------------------------------------------
		DirectGraphicsDevice::DirectGraphicsDevice(HWND _hWnd, float w, float h, bool f) :m_hWnd(_hWnd), m_Width(w), m_Height(h), m_Fullscreen(f)
		{
		}

		DirectGraphicsDevice::~DirectGraphicsDevice()
		{
		}

		//--------------------------------------------------
		//	public function
		//--------------------------------------------------
		bool DirectGraphicsDevice::Initialize()
		{
			if (FAILED(m_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION)))
			{
				OutPutError("Direct3Dオブジェクトの生成に失敗しました");
				return false;
			}

			if (FAILED(m_pDirect3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &m_D3DdisplayMode)))
			{
				OutPutError("DisplayModeの取得に失敗しました");
				return false;
			}

			InitD3Dpp();

			/* HALMode */
			if (FAILED(m_pDirect3D->CreateDevice(
				D3DADAPTER_DEFAULT,
				D3DDEVTYPE_HAL,
				m_hWnd,
				D3DCREATE_SOFTWARE_VERTEXPROCESSING,
				&m_D3dpp, &m_pD3Device)))
			{
				/* REFmode */
				if (FAILED(m_pDirect3D->CreateDevice(
					D3DADAPTER_DEFAULT,
					D3DDEVTYPE_REF,
					m_hWnd,
					D3DCREATE_HARDWARE_VERTEXPROCESSING,
					&m_D3dpp, &m_pD3Device)))
				{
					return false;
				}
			}

			SetRenderlingConfiguration();

			return true;
		}

		void DirectGraphicsDevice::Finalize()
		{
			SafeRelease(m_pD3Device);
			SafeRelease(m_pDirect3D);
		}

		void DirectGraphicsDevice::BeginScene()
		{
			m_pD3Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
			m_pD3Device->BeginScene();
		}

		void DirectGraphicsDevice::EndScene()
		{
			m_pD3Device->EndScene();
			m_pD3Device->Present(NULL, NULL, NULL, NULL);
		}

		//--------------------------------------------------
		//	private function
		//--------------------------------------------------
		void DirectGraphicsDevice::InitD3Dpp()
		{
			//Window
			ZeroMemory(&m_D3dppwnd, sizeof(D3DPRESENT_PARAMETERS));
			m_D3dppwnd.BackBufferWidth = m_Width;
			m_D3dppwnd.BackBufferHeight = m_Height;
			m_D3dppwnd.BackBufferFormat = m_D3DdisplayMode.Format;
			m_D3dppwnd.BackBufferCount = 1;
			m_D3dppwnd.MultiSampleType = D3DMULTISAMPLE_NONE;
			m_D3dppwnd.MultiSampleQuality = 0;
			m_D3dppwnd.SwapEffect = D3DSWAPEFFECT_DISCARD;
			m_D3dppwnd.hDeviceWindow = m_hWnd;
			m_D3dppwnd.Windowed = TRUE;
			m_D3dppwnd.EnableAutoDepthStencil = FALSE;
			//m_D3dppwnd.AutoDepthStencilFormat = ;

			//Full


			m_D3dpp = (m_Fullscreen) ? m_D3dppfull : m_D3dppwnd;
		}

		void DirectGraphicsDevice::SetRenderlingConfiguration()
		{
			m_pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
			m_pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
			m_pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
			m_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
			m_pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
			m_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
			m_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
		}
	}
}