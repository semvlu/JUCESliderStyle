#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    juce::LookAndFeel::setDefaultLookAndFeel(&myCustomLNF);
    addAndMakeVisible(arw1);

    setSize (600, 400);
}

MainComponent::~MainComponent()
{
    // destruct the LookAndFeel object
    juce::LookAndFeel::setDefaultLookAndFeel(nullptr);;

}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));


}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.

    
    arw1.setBounds(getWidth() / 2 - 100, getHeight() / 2 - 100, 200, 200);
}
