#include <Tiny-I2C-Drivers.h>

TinyMCP4728 mcp;

void setup()
{
  mcp.begin();
}

void loop()
{
  mcp.setValue(MCP4728_CHANNEL_A, 4095);
  mcp.setValue(MCP4728_CHANNEL_B, 2048);
  mcp.setValue(MCP4728_CHANNEL_C, 1024);
  mcp.setValue(MCP4728_CHANNEL_D, 0);
  delay(3000);
  mcp.setValue(MCP4728_CHANNEL_A, 0);
  mcp.setValue(MCP4728_CHANNEL_B, 4095);
  mcp.setValue(MCP4728_CHANNEL_C, 2048);
  mcp.setValue(MCP4728_CHANNEL_D, 1024);
  delay(3000);
  mcp.setValue(MCP4728_CHANNEL_C, 4095);
  mcp.setValue(MCP4728_CHANNEL_D, 2048);
  mcp.setValue(MCP4728_CHANNEL_A, 1024);
  mcp.setValue(MCP4728_CHANNEL_B, 0);
  delay(3000);
  mcp.setValue(MCP4728_CHANNEL_D, 4095);
  mcp.setValue(MCP4728_CHANNEL_A, 2048);
  mcp.setValue(MCP4728_CHANNEL_B, 1024);
  mcp.setValue(MCP4728_CHANNEL_C, 0);
  delay(3000);
}
