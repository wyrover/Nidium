#ifndef binding_jsimage_h__
#define binding_jsimage_h__

#include <Core/Messages.h>
#include <IO/Stream.h>
#include <Binding/ClassMapper.h>

namespace Nidium {
namespace Graphics {
class Image;
}
namespace Binding {

class JSImage : public ClassMapperWithEvents<JSImage>, public Core::Messages
{
public:
    JSImage();
    virtual ~JSImage();
    static JSPropertySpec *ListProperties();
    static JSImage *Constructor(JSContext *cx, JS::CallArgs &args,
        JS::HandleObject obj);

    Graphics::Image *m_Image;
    IO::Stream *m_Stream;

    static Graphics::Image *JSObjectToImage(JS::HandleObject obj);
    static void RegisterObject(JSContext *cx);
    static bool JSObjectIs(JSContext *cx, JS::HandleObject obj);
    static JSObject *BuildImageObject(JSContext *cx,
                                      Graphics::Image *image,
                                      const char name[] = NULL);

    void onMessage(const Core::SharedMessages::Message &msg);

protected:
    NIDIUM_DECL_JSGETTERSETTER(src);
private:
    bool setupWithBuffer(buffer *buf);
};

} // namespace Binding
} // namespace Nidium

#endif
