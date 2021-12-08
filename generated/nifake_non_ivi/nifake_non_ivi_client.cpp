
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// EXPERIMENTAL Client convenience wrapper for NI-FAKE-NON-IVI.
//---------------------------------------------------------------------
#include "nifake_non_ivi_client.h"

#include <grpcpp/grpcpp.h>

#include <nifake_non_ivi.grpc.pb.h>

#include <cstdint>
#include <memory>
#include <stdexcept>
#include <vector>

namespace nifake_non_ivi_grpc::experimental::client {

CloseResponse
close(const StubPtr& stub, const nidevice_grpc::Session& handle)
{
  ::grpc::ClientContext context;

  auto request = CloseRequest{};
  request.mutable_handle()->CopyFrom(handle);

  auto response = CloseResponse{};

  raise_if_error(
      stub->Close(&context, request, &response));

  return response;
}

GetMarbleAttributeDoubleResponse
get_marble_attribute_double(const StubPtr& stub, const nidevice_grpc::Session& handle, const simple_variant<MarbleDoubleAttribute, pb::int32>& attribute)
{
  ::grpc::ClientContext context;

  auto request = GetMarbleAttributeDoubleRequest{};
  request.mutable_handle()->CopyFrom(handle);
  const auto attribute_ptr = attribute.get_if<MarbleDoubleAttribute>();
  const auto attribute_raw_ptr = attribute.get_if<pb::int32>();
  if (attribute_ptr) {
    request.set_attribute(*attribute_ptr);
  }
  else if (attribute_raw_ptr) {
    request.set_attribute_raw(*attribute_raw_ptr);
  }

  auto response = GetMarbleAttributeDoubleResponse{};

  raise_if_error(
      stub->GetMarbleAttributeDouble(&context, request, &response));

  return response;
}

GetMarbleAttributeInt32Response
get_marble_attribute_int32(const StubPtr& stub, const nidevice_grpc::Session& handle, const simple_variant<MarbleInt32Attribute, pb::int32>& attribute)
{
  ::grpc::ClientContext context;

  auto request = GetMarbleAttributeInt32Request{};
  request.mutable_handle()->CopyFrom(handle);
  const auto attribute_ptr = attribute.get_if<MarbleInt32Attribute>();
  const auto attribute_raw_ptr = attribute.get_if<pb::int32>();
  if (attribute_ptr) {
    request.set_attribute(*attribute_ptr);
  }
  else if (attribute_raw_ptr) {
    request.set_attribute_raw(*attribute_raw_ptr);
  }

  auto response = GetMarbleAttributeInt32Response{};

  raise_if_error(
      stub->GetMarbleAttributeInt32(&context, request, &response));

  return response;
}

GetMarbleAttributeInt32ArrayResponse
get_marble_attribute_int32_array(const StubPtr& stub, const nidevice_grpc::Session& handle, const simple_variant<MarbleInt32ArrayAttribute, pb::int32>& attribute)
{
  ::grpc::ClientContext context;

  auto request = GetMarbleAttributeInt32ArrayRequest{};
  request.mutable_handle()->CopyFrom(handle);
  const auto attribute_ptr = attribute.get_if<MarbleInt32ArrayAttribute>();
  const auto attribute_raw_ptr = attribute.get_if<pb::int32>();
  if (attribute_ptr) {
    request.set_attribute(*attribute_ptr);
  }
  else if (attribute_raw_ptr) {
    request.set_attribute_raw(*attribute_raw_ptr);
  }

  auto response = GetMarbleAttributeInt32ArrayResponse{};

  raise_if_error(
      stub->GetMarbleAttributeInt32Array(&context, request, &response));

  return response;
}

InitResponse
init(const StubPtr& stub, const pb::string& session_name)
{
  ::grpc::ClientContext context;

  auto request = InitRequest{};
  request.set_session_name(session_name);

  auto response = InitResponse{};

  raise_if_error(
      stub->Init(&context, request, &response));

  return response;
}

InitWithHandleNameAsSessionNameResponse
init_with_handle_name_as_session_name(const StubPtr& stub, const pb::string& handle_name)
{
  ::grpc::ClientContext context;

  auto request = InitWithHandleNameAsSessionNameRequest{};
  request.set_handle_name(handle_name);

  auto response = InitWithHandleNameAsSessionNameResponse{};

  raise_if_error(
      stub->InitWithHandleNameAsSessionName(&context, request, &response));

  return response;
}

InputArraysWithNarrowIntegerTypesResponse
input_arrays_with_narrow_integer_types(const StubPtr& stub, const std::vector<pb::uint32>& u16_array, const std::vector<pb::int32>& i16_array, const std::vector<pb::int32>& i8_array)
{
  ::grpc::ClientContext context;

  auto request = InputArraysWithNarrowIntegerTypesRequest{};
  copy_array(u16_array, request.mutable_u16_array());
  copy_array(i16_array, request.mutable_i16_array());
  copy_array(i8_array, request.mutable_i8_array());

  auto response = InputArraysWithNarrowIntegerTypesResponse{};

  raise_if_error(
      stub->InputArraysWithNarrowIntegerTypes(&context, request, &response));

  return response;
}

IotaWithCustomSizeResponse
iota_with_custom_size(const StubPtr& stub, const pb::int32& size_one, const pb::int32& size_two)
{
  ::grpc::ClientContext context;

  auto request = IotaWithCustomSizeRequest{};
  request.set_size_one(size_one);
  request.set_size_two(size_two);

  auto response = IotaWithCustomSizeResponse{};

  raise_if_error(
      stub->IotaWithCustomSize(&context, request, &response));

  return response;
}

OutputArraysWithNarrowIntegerTypesResponse
output_arrays_with_narrow_integer_types(const StubPtr& stub, const pb::int32& number_of_u16_samples, const pb::int32& number_of_i16_samples, const pb::int32& number_of_i8_samples)
{
  ::grpc::ClientContext context;

  auto request = OutputArraysWithNarrowIntegerTypesRequest{};
  request.set_number_of_u16_samples(number_of_u16_samples);
  request.set_number_of_i16_samples(number_of_i16_samples);
  request.set_number_of_i8_samples(number_of_i8_samples);

  auto response = OutputArraysWithNarrowIntegerTypesResponse{};

  raise_if_error(
      stub->OutputArraysWithNarrowIntegerTypes(&context, request, &response));

  return response;
}

InputArrayOfBytesResponse
input_array_of_bytes(const StubPtr& stub, const pb::string& u8_array)
{
  ::grpc::ClientContext context;

  auto request = InputArrayOfBytesRequest{};
  request.set_u8_array(u8_array);

  auto response = InputArrayOfBytesResponse{};

  raise_if_error(
      stub->InputArrayOfBytes(&context, request, &response));

  return response;
}

OutputArrayOfBytesResponse
output_array_of_bytes(const StubPtr& stub, const pb::int32& number_of_u8_samples)
{
  ::grpc::ClientContext context;

  auto request = OutputArrayOfBytesRequest{};
  request.set_number_of_u8_samples(number_of_u8_samples);

  auto response = OutputArrayOfBytesResponse{};

  raise_if_error(
      stub->OutputArrayOfBytes(&context, request, &response));

  return response;
}

OutputArraysWithPassedInByPtrMechanismResponse
output_arrays_with_passed_in_by_ptr_mechanism(const StubPtr& stub, const pb::int32& array_size)
{
  ::grpc::ClientContext context;

  auto request = OutputArraysWithPassedInByPtrMechanismRequest{};
  request.set_array_size(array_size);

  auto response = OutputArraysWithPassedInByPtrMechanismResponse{};

  raise_if_error(
      stub->OutputArraysWithPassedInByPtrMechanism(&context, request, &response));

  return response;
}

std::unique_ptr<grpc::ClientReader<RegisterCallbackResponse>>
register_callback(const StubPtr& stub, ::grpc::ClientContext& context, const pb::int32& input_data)
{
  auto request = RegisterCallbackRequest{};
  request.set_input_data(input_data);

  return stub->RegisterCallback(&context, request);
}

std::unique_ptr<grpc::ClientReader<ReadStreamResponse>>
read_stream(const StubPtr& stub, ::grpc::ClientContext& context, const pb::int32& start, const pb::int32& stop)
{
  auto request = ReadStreamRequest{};
  request.set_start(start);
  request.set_stop(stop);

  return stub->ReadStream(&context, request);
}

InputTimestampResponse
input_timestamp(const StubPtr& stub, const google::protobuf::Timestamp& when)
{
  ::grpc::ClientContext context;

  auto request = InputTimestampRequest{};
  request.mutable_when()->CopyFrom(when);

  auto response = InputTimestampResponse{};

  raise_if_error(
      stub->InputTimestamp(&context, request, &response));

  return response;
}

OutputTimestampResponse
output_timestamp(const StubPtr& stub)
{
  ::grpc::ClientContext context;

  auto request = OutputTimestampRequest{};

  auto response = OutputTimestampResponse{};

  raise_if_error(
      stub->OutputTimestamp(&context, request, &response));

  return response;
}

InputVarArgsResponse
input_var_args(const StubPtr& stub, const pb::string& input_name, const std::vector<StringAndEnum>& string_and_enums)
{
  ::grpc::ClientContext context;

  auto request = InputVarArgsRequest{};
  request.set_input_name(input_name);
  copy_array(string_and_enums, request.mutable_string_and_enums());

  auto response = InputVarArgsResponse{};

  raise_if_error(
      stub->InputVarArgs(&context, request, &response));

  return response;
}

OutputVarArgsResponse
output_var_args(const StubPtr& stub, const pb::string& input_name, const std::vector<pb::string>& channel_names)
{
  ::grpc::ClientContext context;

  auto request = OutputVarArgsRequest{};
  request.set_input_name(input_name);
  copy_array(channel_names, request.mutable_channel_names());

  auto response = OutputVarArgsResponse{};

  raise_if_error(
      stub->OutputVarArgs(&context, request, &response));

  return response;
}

ResetMarbleAttributeResponse
reset_marble_attribute(const StubPtr& stub, const nidevice_grpc::Session& handle, const simple_variant<MarbleResetAttribute, pb::int32>& attribute)
{
  ::grpc::ClientContext context;

  auto request = ResetMarbleAttributeRequest{};
  request.mutable_handle()->CopyFrom(handle);
  const auto attribute_ptr = attribute.get_if<MarbleResetAttribute>();
  const auto attribute_raw_ptr = attribute.get_if<pb::int32>();
  if (attribute_ptr) {
    request.set_attribute(*attribute_ptr);
  }
  else if (attribute_raw_ptr) {
    request.set_attribute_raw(*attribute_raw_ptr);
  }

  auto response = ResetMarbleAttributeResponse{};

  raise_if_error(
      stub->ResetMarbleAttribute(&context, request, &response));

  return response;
}

SetMarbleAttributeDoubleResponse
set_marble_attribute_double(const StubPtr& stub, const nidevice_grpc::Session& handle, const simple_variant<MarbleDoubleAttribute, pb::int32>& attribute, const double& value)
{
  ::grpc::ClientContext context;

  auto request = SetMarbleAttributeDoubleRequest{};
  request.mutable_handle()->CopyFrom(handle);
  const auto attribute_ptr = attribute.get_if<MarbleDoubleAttribute>();
  const auto attribute_raw_ptr = attribute.get_if<pb::int32>();
  if (attribute_ptr) {
    request.set_attribute(*attribute_ptr);
  }
  else if (attribute_raw_ptr) {
    request.set_attribute_raw(*attribute_raw_ptr);
  }
  request.set_value(value);

  auto response = SetMarbleAttributeDoubleResponse{};

  raise_if_error(
      stub->SetMarbleAttributeDouble(&context, request, &response));

  return response;
}

SetMarbleAttributeInt32Response
set_marble_attribute_int32(const StubPtr& stub, const nidevice_grpc::Session& handle, const simple_variant<MarbleInt32Attribute, pb::int32>& attribute, const simple_variant<MarbleInt32AttributeValues, pb::int32>& value)
{
  ::grpc::ClientContext context;

  auto request = SetMarbleAttributeInt32Request{};
  request.mutable_handle()->CopyFrom(handle);
  const auto attribute_ptr = attribute.get_if<MarbleInt32Attribute>();
  const auto attribute_raw_ptr = attribute.get_if<pb::int32>();
  if (attribute_ptr) {
    request.set_attribute(*attribute_ptr);
  }
  else if (attribute_raw_ptr) {
    request.set_attribute_raw(*attribute_raw_ptr);
  }
  const auto value_ptr = value.get_if<MarbleInt32AttributeValues>();
  const auto value_raw_ptr = value.get_if<pb::int32>();
  if (value_ptr) {
    request.set_value(*value_ptr);
  }
  else if (value_raw_ptr) {
    request.set_value_raw(*value_raw_ptr);
  }

  auto response = SetMarbleAttributeInt32Response{};

  raise_if_error(
      stub->SetMarbleAttributeInt32(&context, request, &response));

  return response;
}

SetColorsResponse
set_colors(const StubPtr& stub, const std::vector<pb::int32>& colors, const pb::int32& size)
{
  ::grpc::ClientContext context;

  auto request = SetColorsRequest{};
  copy_array(colors, request.mutable_colors());
  request.set_size(size);

  auto response = SetColorsResponse{};

  raise_if_error(
      stub->SetColors(&context, request, &response));

  return response;
}

GetStructsWithCoercionResponse
get_structs_with_coercion(const StubPtr& stub, const pb::int32& number_of_structs)
{
  ::grpc::ClientContext context;

  auto request = GetStructsWithCoercionRequest{};
  request.set_number_of_structs(number_of_structs);

  auto response = GetStructsWithCoercionResponse{};

  raise_if_error(
      stub->GetStructsWithCoercion(&context, request, &response));

  return response;
}

SetStructsWithCoercionResponse
set_structs_with_coercion(const StubPtr& stub, const std::vector<StructWithCoercion>& structs)
{
  ::grpc::ClientContext context;

  auto request = SetStructsWithCoercionRequest{};
  copy_array(structs, request.mutable_structs());

  auto response = SetStructsWithCoercionResponse{};

  raise_if_error(
      stub->SetStructsWithCoercion(&context, request, &response));

  return response;
}

InputStringValuedEnumResponse
input_string_valued_enum(const StubPtr& stub, const simple_variant<MobileOSNames, std::string>& a_name)
{
  ::grpc::ClientContext context;

  auto request = InputStringValuedEnumRequest{};
  const auto a_name_ptr = a_name.get_if<MobileOSNames>();
  const auto a_name_raw_ptr = a_name.get_if<std::string>();
  if (a_name_ptr) {
    request.set_a_name_mapped(*a_name_ptr);
  }
  else if (a_name_raw_ptr) {
    request.set_a_name_raw(*a_name_raw_ptr);
  }

  auto response = InputStringValuedEnumResponse{};

  raise_if_error(
      stub->InputStringValuedEnum(&context, request, &response));

  return response;
}

WriteBooleanArrayResponse
write_boolean_array(const StubPtr& stub, const std::vector<bool>& bools)
{
  ::grpc::ClientContext context;

  auto request = WriteBooleanArrayRequest{};
  copy_array(bools, request.mutable_bools());

  auto response = WriteBooleanArrayResponse{};

  raise_if_error(
      stub->WriteBooleanArray(&context, request, &response));

  return response;
}


} // namespace nifake_non_ivi_grpc::experimental::client
