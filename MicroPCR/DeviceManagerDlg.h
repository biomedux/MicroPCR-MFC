#pragma once
#include "DeviceConnect.h"
#include "afxcmn.h"


// DeviceManagerDlg 대화 상자입니다.

class DeviceManagerDlg : public CDialog
{
	DECLARE_DYNAMIC(DeviceManagerDlg)

public:
	DeviceManagerDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~DeviceManagerDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_DEVICE_MANAGER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
