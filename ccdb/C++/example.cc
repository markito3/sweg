#include "CCDB/Providers/MySQLDataProvider.h"
#include "CCDB/MySQLCalibration.h"

using namespace ccdb;

int main() {
  
  bool connection_status = false, get_status = false;
  vector<vector<string>> table;
      
  DataProvider *provider = new MySQLDataProvider();
  string connection_string = "mysql://ccdb_user@hallddb.jlab.org/ccdb";
  connection_status = provider->Connect(connection_string);
  cout << "low level connection_status = " << connection_status << endl;

  MySQLCalibration *calib = new MySQLCalibration(100);
  connection_status = false;
  connection_status = calib->Connect(connection_string);
  cout << "high level connection_status = " << connection_status << endl;
  get_status = calib->GetCalib(table, "/test/test_vars/test_table");
  cout << "get_status = " << get_status << endl;
  int nrows = table.size();
  int ncols = table[0].size();
  cout << "number of rows = " << nrows << endl;
  cout << "number of columns = " << ncols << endl;
  for (int i = 0; i < nrows; i++) {
    for (int j = 0; j < ncols; j++) {
      cout << i << " " << j << " " << table[i][j] << endl;
    }
  }
  exit(0);
}
