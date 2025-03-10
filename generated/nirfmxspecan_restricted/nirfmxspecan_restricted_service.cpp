
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service implementation for the NI-RFMXSPECAN-RESTRICTED Metadata
//---------------------------------------------------------------------
#include "nirfmxspecan_restricted_service.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <atomic>
#include <vector>
#include <server/converters.h>

namespace nirfmxspecan_restricted_grpc {

  using nidevice_grpc::converters::allocate_output_storage;
  using nidevice_grpc::converters::calculate_linked_array_size;
  using nidevice_grpc::converters::convert_from_grpc;
  using nidevice_grpc::converters::convert_to_grpc;
  using nidevice_grpc::converters::MatchState;

  const auto kErrorReadBufferTooSmall = -200229;
  const auto kWarningCAPIStringTruncatedToFitBuffer = 200026;

  NiRFmxSpecAnRestrictedService::NiRFmxSpecAnRestrictedService(
      NiRFmxSpecAnRestrictedLibraryInterface* library,
      ResourceRepositorySharedPtr resource_repository,
      const NiRFmxSpecAnRestrictedFeatureToggles& feature_toggles)
      : library_(library),
      session_repository_(resource_repository),
      feature_toggles_(feature_toggles)
  {
  }

  NiRFmxSpecAnRestrictedService::~NiRFmxSpecAnRestrictedService()
  {
  }

  // Returns true if it's safe to use outputs of a method with the given status.
  inline bool status_ok(int32 status)
  {
    return status >= 0;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiRFmxSpecAnRestrictedService::CacheResult(::grpc::ServerContext* context, const CacheResultRequest* request, CacheResultResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto instrument_grpc_session = request->instrument();
      niRFmxInstrHandle instrument = session_repository_->access_session(instrument_grpc_session.name());
      auto selector_string_mbcs = convert_from_grpc<std::string>(request->selector_string());
      char* selector_string = (char*)selector_string_mbcs.c_str();
      int32 selector_string_out_size = request->selector_string_out_size();
      std::string selector_string_out;
      if (selector_string_out_size > 0) {
          selector_string_out.resize(selector_string_out_size - 1);
      }
      auto status = library_->CacheResult(instrument, selector_string, selector_string_out_size, (char*)selector_string_out.data());
      if (!status_ok(status)) {
        return ConvertApiErrorStatusForNiRFmxInstrHandle(context, status, instrument);
      }
      response->set_status(status);
      std::string selector_string_out_utf8;
      convert_to_grpc(selector_string_out, &selector_string_out_utf8);
      response->set_selector_string_out(selector_string_out_utf8);
      nidevice_grpc::converters::trim_trailing_nulls(*(response->mutable_selector_string_out()));
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::NonDriverException& ex) {
      return ex.GetStatus();
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiRFmxSpecAnRestrictedService::IQFetchDataOverrideBehavior(::grpc::ServerContext* context, const IQFetchDataOverrideBehaviorRequest* request, IQFetchDataOverrideBehaviorResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto instrument_grpc_session = request->instrument();
      niRFmxInstrHandle instrument = session_repository_->access_session(instrument_grpc_session.name());
      auto selector_string_mbcs = convert_from_grpc<std::string>(request->selector_string());
      char* selector_string = (char*)selector_string_mbcs.c_str();
      float64 timeout = request->timeout();
      int32 record_to_fetch = request->record_to_fetch();
      int64 samples_to_read = request->samples_to_read();
      int32 delete_on_fetch;
      switch (request->delete_on_fetch_enum_case()) {
        case nirfmxspecan_restricted_grpc::IQFetchDataOverrideBehaviorRequest::DeleteOnFetchEnumCase::kDeleteOnFetch: {
          delete_on_fetch = static_cast<int32>(request->delete_on_fetch());
          break;
        }
        case nirfmxspecan_restricted_grpc::IQFetchDataOverrideBehaviorRequest::DeleteOnFetchEnumCase::kDeleteOnFetchRaw: {
          delete_on_fetch = static_cast<int32>(request->delete_on_fetch_raw());
          break;
        }
        case nirfmxspecan_restricted_grpc::IQFetchDataOverrideBehaviorRequest::DeleteOnFetchEnumCase::DELETE_ON_FETCH_ENUM_NOT_SET: {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for delete_on_fetch was not specified or out of range");
          break;
        }
      }

      float64 t0 {};
      float64 dt {};
      int32 actual_array_size {};
      while (true) {
        auto status = library_->IQFetchDataOverrideBehavior(instrument, selector_string, timeout, record_to_fetch, samples_to_read, delete_on_fetch, &t0, &dt, nullptr, 0, &actual_array_size);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNiRFmxInstrHandle(context, status, instrument);
        }
        std::vector<NIComplexSingle> data(actual_array_size, NIComplexSingle());
        auto array_size = actual_array_size;
        status = library_->IQFetchDataOverrideBehavior(instrument, selector_string, timeout, record_to_fetch, samples_to_read, delete_on_fetch, &t0, &dt, data.data(), array_size, &actual_array_size);
        if (status == kErrorReadBufferTooSmall || status == kWarningCAPIStringTruncatedToFitBuffer) {
          // buffer is now too small, try again
          continue;
        }
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNiRFmxInstrHandle(context, status, instrument);
        }
        response->set_status(status);
        response->set_t0(t0);
        response->set_dt(dt);
        convert_to_grpc(data, response->mutable_data());
        {
          auto shrunk_size = actual_array_size;
          auto current_size = response->mutable_data()->size();
          if (shrunk_size != current_size) {
            response->mutable_data()->DeleteSubrange(shrunk_size, current_size - shrunk_size);
          }
        }
        response->set_actual_array_size(actual_array_size);
        return ::grpc::Status::OK;
      }
    }
    catch (nidevice_grpc::NonDriverException& ex) {
      return ex.GetStatus();
    }
  }


  NiRFmxSpecAnRestrictedFeatureToggles::NiRFmxSpecAnRestrictedFeatureToggles(
    const nidevice_grpc::FeatureToggles& feature_toggles)
    : is_enabled(
        feature_toggles.is_feature_enabled("nirfmxspecan_restricted", CodeReadiness::kRestrictedRelease))
  {
  }
} // namespace nirfmxspecan_restricted_grpc

