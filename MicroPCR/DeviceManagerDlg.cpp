// DeviceManagerDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MicroPCR.h"
#include "DeviceManagerDlg.h"


// DeviceManagerDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(DeviceManagerDlg, CDialog)

DeviceManagerDlg::DeviceManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(DeviceManagerDlg::IDD, pParent)
{

}

DeviceManagerDlg::~DeviceManagerDlg()
{
}

void DeviceManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DEVICE, m_cDeviceList);
}


BEGIN_MESSAGE_MAP(DeviceManagerDlg, CDialog)
	ON_WM_DEVICECHANGE()
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &DeviceManagerDlg::OnBnClickedButtonCancel)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_DEVICE, &DeviceManagerDlg::OnNMDblclkListDevice)
END_MESSAGE_MAP()


BOOL DeviceManagerDlg::OnDeviceChange(UINT nEventType, DWORD dwData)
{
	CStringArray *devices = device->CheckDevice();

	m_cDeviceList.DeleteAllItems();
	if (devices != NULL)
	{
		for (int i = 0; i < devices->GetSize(); i++)
			m_cDeviceList.InsertItem(i, devices->GetAt(i).GetString());
	}
	return TRUE;
}

// DeviceManagerDlg 메시지 처리기입니다.

void DeviceManagerDlg::OnBnClickedButtonCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog::OnCancel();
	SendMessage(WM_CLOSE, NULL, NULL);
}

void DeviceManagerDlg::OnNMDblclkListDevice(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	int index = pNMItemActivate->iItem;

	if (index != -1)
	{
		target = m_cDeviceList.GetItemText(index, 0);
		CDialog::OnOK();
	}

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}

BOOL DeviceManagerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	device = new CDeviceConnect( GetSafeHwnd() );
	CStringArray *devices = device->CheckDevice();

	m_cDeviceList.DeleteAllItems();
	if (devices != NULL)
	{
		for (int i = 0; i < devices->GetSize(); i++)
			m_cDeviceList.InsertItem(i, devices->GetAt(i).GetString());
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
