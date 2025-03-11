
#include "ExampleLayer.h"

ExampleLayer::ExampleLayer()
{

}

void ExampleLayer::OnAttach()
{

}

void ExampleLayer::OnDetach()
{

}

void ExampleLayer::OnUpdate()
{
    
}

void ExampleLayer::OnEvent(Bell::Event& event)
{
    Engine_TRACE("{0}", event);
}