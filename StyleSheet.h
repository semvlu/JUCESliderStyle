/*
  ==============================================================================

    StyleSheet.h
    Created: 30 Sep 2022 6:00:51pm
    Author:  David

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

namespace juce
{
    class customLNF : public juce::LookAndFeel_V4
    {
    public:
        void drawRotarySlider(Graphics&, int x, int y, int width, int height, 
            float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider&);
    };

    class arrowKnob : public Slider
    {
    public:
        arrowKnob()
        {
            // set rotation 
            auto rotaryParams = getRotaryParameters();
            rotaryParams.startAngleRadians = juce::MathConstants<float>::pi * 1.5f;
            rotaryParams.endAngleRadians = juce::MathConstants<float>::pi * 3.0f;
            setRotaryParameters(rotaryParams);

            // set slider params
            setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
            setRange(0.0f, 100.0f);
            setValue(25.0f);
            setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 25);

            // set colours
            setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colours::teal);
            setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::teal);
        }
    private:

    };
}