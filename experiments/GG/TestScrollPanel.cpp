#include <GG/GUI.h>
#include <GG/Clr.h>
#include <GG/ClrConstants.h>
#include <GG/dialogs/ThreeButtonDlg.h>
#include <GG/StyleFactory.h>
#include <GG/ScrollPanel.h>

#include <GG/RichText/RichText.h>
#include <GG/RichText/ImageBlock.h>

#include "TestApp.h"
#include "TestDialog.h"

int main(int argc, char* argv[])
{

    TestApp app(argc, argv);

    const std::string message = "Are <i>we</i> Готово yet?"; // That Russian word means "Done", ha.
    const std::set<GG::UnicodeCharset> charsets_ = GG::UnicodeCharsetsToRender(message);
    const std::vector<GG::UnicodeCharset> charsets(charsets_.begin(), charsets_.end());

    const boost::shared_ptr<GG::Font> font =
    GG::GUI::GetGUI()->GetStyleFactory()->DefaultFont(12, &charsets[0], &charsets[0] + charsets.size());

    GG::ImageBlock::SetDefaultImagePath("../../default/");

    GG::Wnd* box = new GG::RichText(GG::X(10), GG::Y(10), GG::X(300), GG::Y(200),
                                    "The essence of a true text layout lies in <i>its capability</i> to fit the text into regions it determines "
                                    "from the other things it believes to be relevat to the layout of the text in the regions to which it is laying out the text. "
                                    "This figure should clarify the matter: <img data/art/icons/combat.png></img> As can be seens from that glorious exepelar, "
                                    "much truth is reachable by the human mind<img data/does.not.exist.png></img> only given the information it comprises is in a form that can be made into "
                                    " truth by the human thought organ.\n"
                                    "Nevertheless, true <confusing>of people can only <i>arise "
                                    "<img data/art/icons/combat.png></img>"
                                    " from constant<u>struggle <rgba 100 200 250 255>and</rgba> strife</u> as bill </i> said.</confusing>"
                                    , font, GG::CLR_GREEN);

    GG::Wnd* scrollPanel = new GG::ScrollPanel(GG::X0, GG::Y0, GG::X(100), GG::Y(100), box);

    TestDialog* dlg = new TestDialog(scrollPanel, font);


    app.Run( dlg );

    return 0;
}
