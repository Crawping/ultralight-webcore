#include "config.h"
#include "DragData.h"
#include <wtf/text/WTFString.h>
#include "NotImplemented.h"

namespace WebCore {

bool DragData::containsURL(FilenameConversionPolicy filenamePolicy) const
{
  notImplemented();
  return false;
}

String DragData::asURL(FilenameConversionPolicy filenamePolicy, String* title) const
{
  notImplemented();
  return String();
}

bool DragData::containsFiles() const
{
  notImplemented();
  return false;
}

unsigned DragData::numberOfFiles() const
{
  notImplemented();
  return 0;
}

void DragData::asFilenames(Vector<String>& result) const
{
  notImplemented();
}

bool DragData::containsPlainText() const
{
  notImplemented();
  return false;
}

String DragData::asPlainText() const
{
  notImplemented();
  return String();
}

bool DragData::containsColor() const
{
  notImplemented();
  return false;
}

bool DragData::canSmartReplace() const
{
  notImplemented();
  return false;
}

bool DragData::containsCompatibleContent() const
{
  notImplemented();
  return false;
}

Color DragData::asColor() const
{
  notImplemented();
  return Color();
}

}  // namespace WebCore
