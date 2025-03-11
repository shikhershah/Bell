#ifndef EXAMPLELAYER_H
#define EXAMPLELAYER_H

#include <Bell.h>

class ExampleLayer : public  Bell::Layer
{
private:
    /* data */
public:
    ExampleLayer();
    virtual ~ExampleLayer() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;
    virtual void OnUpdate() override;

    virtual void OnEvent(Bell::Event& event) override;

};




#endif //EXAMPLELAYER_H