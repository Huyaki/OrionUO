// MIT License
// Copyright (C) August 2016 Hotride

#pragma once

class CGumpSelectColor : public CGump
{
protected:
    static const int ID_GSC_BUTTON_OKAY = 1;
    static const int ID_GSC_SLIDER = 2;
    static const int ID_GSC_COLORS = 10;

    SELECT_COLOR_GUMP_STATE m_State;
    uint8_t m_ColorRef{ 1 };
    int m_SelectedIndex{ 10 };

    CGUISlider *m_Slider{ nullptr };
    CGUIDataBox *m_DataBox{ nullptr };

public:
    CGumpSelectColor(uint32_t serial, short x, short y, SELECT_COLOR_GUMP_STATE state);
    virtual ~CGumpSelectColor();

    virtual void UpdateContent();

    GUMP_BUTTON_EVENT_H;
    GUMP_SLIDER_CLICK_EVENT_H;
    GUMP_SLIDER_MOVE_EVENT_H;

    virtual void OnSelectColor(uint16_t color);
};
