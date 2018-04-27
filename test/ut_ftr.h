// ut_ftr.h
// Fast to directory using windows command line
#include "../src/CmdObject.h"
#include "../src/CmdList.h"

class FastToRunTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    cmdList = new CmdList();
    networkObject = new CmdObject("network", "ping 1.1.1.1 -t", "this is a dns test");
    folderObject1 = new CmdObject("design pattern", "cd C:/Users/rankaitsai/Desktop/Important/NTUT/NTUT 106-2/Design Pattern", "cd path to design pattern folder");
    folderObject2 = new CmdObject("self", "cd C:/User/rankaitsai/Desktop/Important/Self", "cd path to self folder");
    //networkObject->add();
    cmdList->add(networkObject);
    cmdList->add(folderObject1);
    cmdList->add(folderObject2);
    //add(folderObject);
    //folderObject->add();
  }

  CmdList *cmdList;
  CmdObject *networkObject;
  CmdObject *folderObject1;
  CmdObject *folderObject2;
};

// TEST_F(FastToDirectoryTest, networkTest) {
//   ASSERT_EQ("ping 1.1.1.1 -t", networkObject->getWindowsCommandName());
// }

TEST_F(FastToRunTest, folderExistFromVector) {
  ASSERT_TRUE(cmdList->isExist(folderObject1));
  ASSERT_TRUE(cmdList->isExist(folderObject2));
}

TEST_F(FastToRunTest, DeleteFolderObjectFromVector) {
  cmdList->del(folderObject2);
  ASSERT_FALSE(cmdList->isExist(folderObject2));
}

//
TEST_F(FastToRunTest, SizeOfCmdList) {
  cmdList->del(folderObject1);
  cmdList->del(folderObject2);
  ASSERT_EQ(1, cmdList->count());
}

TEST_F(FastToRunTest, PrintAllInVector) {
  ASSERT_EQ("sddfssfd", cmdList->printAll());
}
