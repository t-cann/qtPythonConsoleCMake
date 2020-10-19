//
// src/DataArray.cpp
//
// (c) British Crown Owned Copyright 2019/AWE
//
// This file is part of TIO browse
// Released under the BSD 3-clause license.
// For more details see license.txt
//

#include "DataArray.h"

#include <QVariant>
#include <string>

#include "ErrorDialog.h"
#include "TIOTypeNames.h"

DataArray::DataArray(const std::string &name, const TIO_Dims_t &nDims,
                     const TIO_Size_t *dims, const ArrayType &arrayType,
                     const TIO_Data_t &dataType)
    : m_name(name),
      m_nDims(nDims),
      m_dims(nullptr),
      m_dataType(dataType),
      m_arrayLength(0),
      m_arrayType(arrayType),
      m_data(nullptr) {
  m_dims = new TIO_Size_t[nDims];
  for (int i = 0; i < nDims; ++i) {
    m_dims[i] = dims[i];
  }
  CalculateArrayLength();
  AllocateMemory();
}

DataArray::~DataArray() {
  DeallocateMemory();
  if (m_dims != nullptr) {
    delete[] m_dims;
    m_dims = nullptr;
  }
}

TIO_Data_t DataArray::getTIODataType() const { return m_dataType; }

TIO_Size_t DataArray::getArrayLength() const { return m_arrayLength; }

TIO_Size_t DataArray::getDim(const int &index) const {
  if (index >= 0 && index < m_nDims) {
    return m_dims[index];
  } else {
    return 0;
  }
}

std::string DataArray::getName() const { return m_name; }

int DataArray::getNDims() const { return m_nDims; }

void *DataArray::getVoidPointer() const { return m_data; }

QVariant DataArray::toQVariant(const int &index) const {
  switch (m_arrayType) {
    // Array is some kind of TIO_Data_t
    case TYPE_DATA:
      switch (m_dataType) {
        case TIO_DATATYPE_NULL:
          return "TIO_DATATYPE_NULL";
          break;
        case TIO_SHORT:
          return QVariant::fromValue(static_cast<short *>(m_data)[index]);
          break;
        case TIO_USHORT:
          return QVariant::fromValue(
              static_cast<unsigned short *>(m_data)[index]);
          break;
        case TIO_INT:
          return QVariant::fromValue(static_cast<int *>(m_data)[index]);
          break;
        case TIO_UINT:
          return QVariant::fromValue(
              static_cast<unsigned int *>(m_data)[index]);
          break;
        case TIO_LONG:
          return QVariant::fromValue(static_cast<long *>(m_data)[index]);
          break;
        case TIO_ULONG:
          return QVariant::fromValue(
              static_cast<unsigned long *>(m_data)[index]);
          break;
        case TIO_LLONG:
          return QVariant::fromValue(static_cast<long long *>(m_data)[index]);
          break;
        case TIO_ULLONG:
          return QVariant::fromValue(
              static_cast<unsigned long long *>(m_data)[index]);
          break;
        case TIO_FLOAT:
          return QVariant::fromValue(static_cast<float *>(m_data)[index]);
          break;
        case TIO_DOUBLE:
          return QVariant::fromValue(static_cast<double *>(m_data)[index]);
          break;
        case TIO_LDOUBLE:
          return QVariant::fromValue(
              static_cast<double>(static_cast<long double *>(m_data)[index]));
          break;
        case TIO_LOGICAL:
          return QVariant::fromValue(
              static_cast<unsigned int *>(m_data)[index]);
          break;
        case TIO_CHAR:
          return QVariant::fromValue(static_cast<char *>(m_data)[index]);
          break;
        case TIO_UCHAR:
          return QVariant::fromValue(
              static_cast<unsigned char *>(m_data)[index]);
          break;
        case TIO_ENUM_T:
          return "TIO_ENUM_T";
          break;
        case TIO_SIZE_T:
          return "TIO_SIZE_T";
          break;
        case TIO_STEP_T:
          return "TIO_STEP_T";
          break;
        case TIO_TIME_T:
          return "TIO_TIME_T";
          break;
        case TIO_STRING:
          return QString::fromStdString(
              std::string(static_cast<char(*)[TIO_STRLEN]>(m_data)[index]));
          break;
      }
      break;
    case TYPE_SHAPE: {
      // Data is TIO_Shape_t, return the shape name
      TIO_Shape_t shape = static_cast<TIO_Shape_t *>(m_data)[index];
      if (shape > 0) {
        return QString::fromStdString("Polygon " + std::to_string(shape));
      } else {
        return QString::fromStdString(TIOTypeNames::TIO_SHAPE[shape]);
      }
    } break;
    case TYPE_NODES_PER_CELL: {
      // Data is TIO_Shape_t, return the node count
      TIO_Shape_t shape = static_cast<TIO_Shape_t *>(m_data)[index];
      if (shape > 0) {
        return QVariant::fromValue(static_cast<int>(shape));
      } else {
        return QVariant::fromValue(TIOTypeNames::TIO_SHAPE_NODE_COUNTS[shape]);
      }
    } break;
    default:
      ErrorDialog("Error: unexpected array type");
  }

  // Default
  return QVariant();
}

std::string DataArray::toString(const int &index) const {
  return toQVariant(index).toString().toStdString();
}

//! Allocate memory and save pointer int m_data;
void DataArray::AllocateMemory() {
  switch (m_arrayType) {
    case TYPE_DATA:
      if (m_arrayLength > 0) {
        switch (m_dataType) {
          case TIO_DATATYPE_NULL:
            m_data = nullptr;
            break;
          case TIO_SHORT:
            m_data = new short[m_arrayLength];
            break;
          case TIO_USHORT:
            m_data = new unsigned short[m_arrayLength];
            break;
          case TIO_INT:
            m_data = new int[m_arrayLength];
            break;
          case TIO_UINT:
            m_data = new unsigned int[m_arrayLength];
            break;
          case TIO_LONG:
            m_data = new long[m_arrayLength];
            break;
          case TIO_ULONG:
            m_data = new unsigned[m_arrayLength];
            break;
          case TIO_LLONG:
            m_data = new long long[m_arrayLength];
            break;
          case TIO_ULLONG:
            m_data = new unsigned long long[m_arrayLength];
            break;
          case TIO_FLOAT:
            m_data = new float[m_arrayLength];
            break;
          case TIO_DOUBLE:
            m_data = new double[m_arrayLength];
            break;
          case TIO_LDOUBLE:
            m_data = new long double[m_arrayLength];
            break;
          case TIO_LOGICAL:
            m_data = new unsigned int[m_arrayLength];
            break;
          case TIO_CHAR:
            m_data = new char[m_arrayLength];
            break;
          case TIO_UCHAR:
            m_data = new unsigned char[m_arrayLength];
            break;
          case TIO_ENUM_T:
            // Shouldn't be here
            break;
          case TIO_SIZE_T:
            // Shouldn't be here
            break;
          case TIO_STEP_T:
            // Shouldn't be here
            break;
          case TIO_TIME_T:
            // Shouldn't be here
            break;
          case TIO_STRING:
            m_data = new char[m_arrayLength][TIO_STRLEN];
            break;
          default:
            ErrorDialog("Error: unexpected data type");
            m_data = nullptr;
        }
      }
      break;
    case TYPE_SHAPE:
    // no break
    case TYPE_NODES_PER_CELL:
      m_data = new TIO_Shape_t[m_arrayLength];
      break;
    default:
      ErrorDialog("Error: unexpected array type");
  }
}

void DataArray::CalculateArrayLength() {
  if (m_nDims > 0 && m_dims[0] > 0) {
    m_arrayLength = 1;
  }
  for (int i = 0; i < m_nDims; ++i) {
    m_arrayLength *= m_dims[i];
  }
}

void DataArray::DeallocateMemory() {
  if (m_data != nullptr) {
    switch (m_arrayType) {
      case TYPE_DATA:
        switch (m_dataType) {
          case TIO_DATATYPE_NULL:
            break;
          case TIO_SHORT:
            delete[] static_cast<short *>(m_data);
            m_data = nullptr;
            break;
          case TIO_USHORT:
            delete[] static_cast<unsigned short *>(m_data);
            m_data = nullptr;
            break;
          case TIO_INT:
            delete[] static_cast<int *>(m_data);
            m_data = nullptr;
            break;
          case TIO_UINT:
            delete[] static_cast<unsigned int *>(m_data);
            m_data = nullptr;
            break;
          case TIO_LONG:
            delete[] static_cast<long *>(m_data);
            m_data = nullptr;
            break;
          case TIO_ULONG:
            delete[] static_cast<unsigned *>(m_data);
            m_data = nullptr;
            break;
          case TIO_LLONG:
            delete[] static_cast<long long *>(m_data);
            m_data = nullptr;
            break;
          case TIO_ULLONG:
            delete[] static_cast<unsigned long long *>(m_data);
            m_data = nullptr;
            break;
          case TIO_FLOAT:
            delete[] static_cast<float *>(m_data);
            m_data = nullptr;
            break;
          case TIO_DOUBLE:
            delete[] static_cast<double *>(m_data);
            m_data = nullptr;
            break;
          case TIO_LDOUBLE:
            delete[] static_cast<long double *>(m_data);
            m_data = nullptr;
            break;
          case TIO_LOGICAL:
            delete[] static_cast<unsigned int *>(m_data);
            m_data = nullptr;
            break;
          case TIO_CHAR:
            delete[] static_cast<char *>(m_data);
            m_data = nullptr;
            break;
          case TIO_UCHAR:
            delete[] static_cast<unsigned char *>(m_data);
            m_data = nullptr;
            break;
          case TIO_ENUM_T:
            // Shouldn't be here
            m_data = nullptr;
            break;
          case TIO_SIZE_T:
            // Shouldn't be here
            m_data = nullptr;
            break;
          case TIO_STEP_T:
            // Shouldn't be here
            m_data = nullptr;
            break;
          case TIO_TIME_T:
            // Shouldn't be here
            m_data = nullptr;
            break;
          case TIO_STRING:
            delete[] static_cast<char *>(m_data);
            m_data = nullptr;
            break;
          default:
            ErrorDialog("Error: unexpected data type");
            m_data = nullptr;
        }
        break;
      case TYPE_SHAPE:
      // no break
      case TYPE_NODES_PER_CELL:
        delete[] static_cast<TIO_Shape_t *>(m_data);
        m_data = nullptr;
        break;
      default:
        ErrorDialog("Error: unexpected array type");
    }
  }
}
