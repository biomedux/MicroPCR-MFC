// DeviceManagerDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MicroPCR.h"
#include "DeviceManagerDlg.h"


// DeviceManagerDlg ��ȭ �����Դϴ�.

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

// DeviceManagerDlg �޽��� ó�����Դϴ�.

void DeviceManagerDlg::OnBnClickedButtonCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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

	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}

BOOL DeviceManagerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	device = new CDeviceConnect( GetSafeHwnd() );
	CStringArray *devices = device->CheckDevice();

	m_cDeviceList.DeleteAllItems();
	if (devices != NULL)
	{
		for (int i = 0; i < devices->GetSize(); i++)
			m_cDeviceList.InsertItem(i, devices->GetAt(i).GetString());
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
