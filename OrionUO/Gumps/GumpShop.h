// MIT License
// Copyright (C) August 2016 Hotride

#pragma once

class CGumpShop : public CGump
{
public:
    bool IsBuyGump = false;

private:
    static const int ID_GB_BUTTON_ACCEPT = 1;
    static const int ID_GB_BUTTON_CLEAR = 2;
    static const int ID_GB_SHOP_LIST = 3;
    static const int ID_GB_SHOP_RESULT = 4;

    int m_ContinueCounter{ 0 };

    void UpdateTotalPrice();

public:
    CGumpShop(uint32_t serial, bool isBuyGump, short x, short y);
    virtual ~CGumpShop();

    CGUIHTMLGump *m_ItemList[2];
    CGUIText *m_TotalPriceText{ nullptr };
    CGUIText *m_TotalGoldText{ nullptr };
    CGUIText *m_NameText{ nullptr };

    void SendList();

    virtual void PrepareContent();

    virtual bool CanBeDisplayed() { return Visible; }

    GUMP_BUTTON_EVENT_H;
    GUMP_SCROLL_BUTTON_EVENT_H;

    virtual void OnLeftMouseButtonUp();
    virtual bool OnLeftMouseButtonDoubleClick();
};
