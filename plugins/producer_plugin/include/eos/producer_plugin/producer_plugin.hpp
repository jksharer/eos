/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */

#pragma once

#include <eos/chain_plugin/chain_plugin.hpp>

#include <appbase/application.hpp>

namespace eosio {

namespace block_production_condition {
   enum block_production_condition_enum
   {
      produced = 0,
      not_synced = 1,
      not_my_turn = 2,
      not_time_yet = 3,
      no_private_key = 4,
      low_participation = 5,
      lag = 6,
      consecutive = 7,
      exception_producing_block = 8
   };
}

class producer_plugin : public appbase::plugin<producer_plugin> {
public:
   APPBASE_PLUGIN_REQUIRES((chain_plugin))

   producer_plugin();
   virtual ~producer_plugin();

   virtual void set_program_options(
      boost::program_options::options_description &command_line_options,
      boost::program_options::options_description &config_file_options
      ) override;

   virtual void plugin_initialize(const boost::program_options::variables_map& options);
   virtual void plugin_startup();
   virtual void plugin_shutdown();

private:
   std::unique_ptr<class producer_plugin_impl> my;
};

} //eos
