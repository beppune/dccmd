#include <xlnt/xlnt.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>

#include <iostream>

namespace po = boost::program_options;

int main(int argc, char *argv[])
{
    
    po::options_description desc{""};
    desc.add_options()
        ("help", "print help message")
        ("url", "download url")
    ;
    
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
    
    if( vm.count("help") ) {
        
        std::cout << desc << "\n";
        return 0;        
    }
    
    /*xlnt::workbook wb;
    xlnt::worksheet ws = wb.active_sheet();
    ws.cell("A1").value(5);
    ws.cell("B2").value("string data");
    ws.cell("C3").formula("=RAND()");
    ws.merge_cells("C3:C4");
    ws.freeze_panes("B2");
    wb.save("example.xlsx");*/
    return 0;
}
// compile with -std=c++14 -Ixlnt/include -lxlnt