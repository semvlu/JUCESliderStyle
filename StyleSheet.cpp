#include "StyleSheet.h"

namespace juce
{
    void customLNF::drawRotarySlider(Graphics& g, int x, int y, int width, int height, 
        float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
    {
        // NO NEED TO EDIT HERE
        auto outline = slider.findColour(Slider::rotarySliderOutlineColourId);
        auto fill = slider.findColour(Slider::rotarySliderFillColourId);

        auto bounds = Rectangle<int>(x, y, width, height).toFloat().reduced(10);

        auto radius = jmin(bounds.getWidth(), bounds.getHeight()) / 2.0f;
        auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        auto lineW = jmin(8.0f, radius * 0.5f);
        auto arcRadius = radius - lineW * 0.5f;
        // NO NEED TO EDIT HERE

        // slider path bg
        Path backgroundArc;
        backgroundArc.addCentredArc(bounds.getCentreX(),
            bounds.getCentreY(),
            arcRadius,
            arcRadius,
            0.0f,
            rotaryStartAngle,
            rotaryEndAngle,
            true);

        g.setColour(outline);
        g.strokePath(backgroundArc, PathStrokeType(lineW, PathStrokeType::curved, PathStrokeType::rounded));

        if (slider.isEnabled())
        {
            // fill path
            Path valueArc;
            valueArc.addCentredArc(bounds.getCentreX(),
                bounds.getCentreY(),
                arcRadius,
                arcRadius,
                0.0f,
                rotaryStartAngle,
                toAngle,
                true);

            g.setColour(fill);
            g.strokePath(valueArc, PathStrokeType(lineW, PathStrokeType::curved, PathStrokeType::rounded));
        }

        // arrow
        Point<float> thumbPoint(bounds.getCentreX() + (arcRadius - 6.0f) * std::cos(toAngle - MathConstants<float>::halfPi),
                                bounds.getCentreY() + (arcRadius - 6.0f) * std::sin(toAngle - MathConstants<float>::halfPi));

        g.setColour(slider.findColour(Slider::thumbColourId));

        auto arwLine = juce::Line<int>(backgroundArc.getBounds().getCentreX(), backgroundArc.getBounds().getCentreY(),
            thumbPoint.getX(), thumbPoint.getY()).toFloat();

        // len = sqrt(pow(x, 2) + pow(y, 2))
        auto arwLen = sqrt(pow(thumbPoint.getX() - backgroundArc.getBounds().getCentreX(), 2) +
            pow(thumbPoint.getY() - backgroundArc.getBounds().getCentreY(), 2));
        g.drawArrow(arwLine, lineW, 8.0f, arwLen);

        // draw a circle at the centre
        g.fillEllipse(Rectangle<float> (15.0f, 15.0f).withCentre(backgroundArc.getBounds().getCentre() ) );

        //g.drawLine(backgroundArc.getBounds().getCentreX(), backgroundArc.getBounds().getCentreY(), 
        //    thumbPoint.getX(), thumbPoint.getY(), lineW);
    }
}