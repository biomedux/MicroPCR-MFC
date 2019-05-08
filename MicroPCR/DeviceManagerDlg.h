#pragma once
#include "DeviceConnect.h"
#include "afxcmn.h"


// DeviceManagerDlg ��ȭ �����Դϴ�.

class DeviceManagerDlg : public CDialog
{
	DECLARE_DYNAMIC(DeviceManagerDlg)

public:
	DeviceManagerDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~DeviceManagerDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_DEVICE_MANAGER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

private:
	
	CDeviceConnect *device;

public:
	CListCtrl m_cDeviceList;
	CString target;

	BOOL OnDeviceChange(UINT nEventType, DWORD dwData);
	afx_msg void OnBnClickedButtonCancel();
	afx_msg void OnNMDblclkListDevice(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
};
